import base64
import json
import re
import requests
from openai import OpenAI

# 1. Initialize OpenAI client
client = OpenAI(api_key="YOUR_OPENAI_API_KEY")


def extract_folder_id(drive_link_or_id):
    """Extracts clean folder ID from link or raw ID."""
    match = re.search(r"folders/([a-zA-Z0-9_-]+)", drive_link_or_id)
    return match.group(1) if match else drive_link_or_id.strip()


def get_public_photos(folder_id):
    """Scrapes image info from a public Google Drive folder without using API keys."""
    print("Connecting to public Google Drive folder...")
    url = f"https://google.com{folder_id}"

    try:
        response = requests.get(url, headers={"User-Agent": "Mozilla/5.0"})
        response.raise_for_status()
    except Exception as e:
        print(f"Error accessing folder: {e}")
        return []

    # Find file metadata embedded in the public page source
    init_data_match = re.search(
        r"init\s*\(\s*(\[.*?\])\s*,\s*\[", response.text, re.DOTALL
    )
    if not init_data_match:
        print(
            "Could not read folder data. Double check that sharing is set to 'Anyone with the link'!"
        )
        return []

    try:
        raw_items = json.loads(init_data_match.group(1))
    except Exception:
        print("Failed to parse folder contents.")
        return []

    image_payloads = []
    # Filter for files that are images
    for item in raw_items:
        file_id = item[0]
        file_name = item[1]
        mime_type = item[3]

        if "image" in str(mime_type):
            print(f"Downloading: {file_name}...")

            # Direct download endpoint for public files
            download_url = (
                f"https://google.com{file_id}"
            )
            try:
                img_resp = requests.get(download_url)
                if img_resp.status_code == 200:
                    base64_image = base64.b64encode(img_resp.content).decode(
                        "utf-8"
                    )
                    image_payloads.append(
                        {
                            "name": file_name,
                            "url": f"data:{mime_type};base64,{base64_image}",
                        }
                    )
            except Exception as e:
                print(f"Skipping {file_name} due to download error: {e}")

    return image_payloads


def rank_photos_for_instagram(images):
    """Sends public images to GPT-4o to pick the top 4 for an Instagram Story."""
    if not images:
        print("No images found to analyze.")
        return

    content_list = [
        {
            "type": "text",
            "text": (
                "You are an expert social media curator and Instagram aesthetic specialist. "
                "I am providing you with multiple photos from my photoshoot. "
                "Please analyze all of them and select the TOP 4 BEST photos to post in an Instagram Story sequence. "
                "For each of the 4 picks, mention the file name, why it works well (lighting, framing, expression, engagement potential), "
                "and suggest a catchy story caption or sticker placement idea."
            ),
        }
    ]

    for img in images:
        content_list.append({"type": "text", "text": f"File Name: {img['name']}"})
        content_list.append(
            {"type": "image_url", "image_url": {"url": img["url"]}}
        )

    print("Sending photos to ChatGPT for aesthetic curation...")
    response = client.chat.completions.create(
        model="gpt-4o",
        messages=[{"role": "user", "content": content_list}],
        max_tokens=1000,
    )

    print("\n--- INSTAGRAM STORY RECOMMENDATIONS ---\n")
    print(response.choices.message.content)


if __name__ == "__main__":
    folder_input = input("Enter your public Google Drive folder link: ")
    folder_id = extract_folder_id(folder_input)

    photos = get_public_photos(folder_id)
    rank_photos_for_instagram(photos)
