#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 128

typedef struct {
    char name[MAX];
    int age;
    int intelligence;
    int luck;
} Human;

void loading(void);
void analyze(Human *person);
void birthdayProtocol(Human *person);
void decodeMessage(void);
void matrixEffect(void);

int main(void)
{
    Human subject;

    strcpy(subject.name, "YOUR_FRIEND");
    subject.age = 18;
    subject.intelligence = 100;
    subject.luck = 50;

    printf("============================================\n");
    printf("       HUMAN SYSTEM DIAGNOSTIC v4.2\n");
    printf("============================================\n\n");

    printf("[+] Initializing birthday protocol...\n");
    loading();

    printf("[+] Subject identified: %s\n", subject.name);
    printf("[+] Running psychological diagnostics...\n\n");

    analyze(&subject);

    printf("\n[+] Calculating yearly upgrade...\n");
    birthdayProtocol(&subject);

    printf("\n[+] Encrypting final birthday message...\n");
    matrixEffect();

    printf("\n[+] Decryption successful.\n\n");

    decodeMessage();

    printf("\n============================================\n");
    printf("             SYSTEM STATUS: OLD\n");
    printf("============================================\n");

    return 0;
}

void loading(void)
{
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);

        for (volatile long j = 0; j < 80000000; j++);
    }

    printf("\n\n");
}

void analyze(Human *person)
{
    printf("Name          : %s\n", person->name);
    printf("Age           : %d\n", person->age);
    printf("Intelligence  : %d/100\n", person->intelligence);
    printf("Luck          : %d/100\n", person->luck);

    if (person->intelligence >= 100)
        printf("Status        : Suspiciously intelligent\n");

    if (person->luck < 60)
        printf("Warning       : Luck stat needs patching\n");

    printf("Conclusion    : Somehow still functioning.\n");
}

void birthdayProtocol(Human *person)
{
    int oldAge = person->age;

    person->age++;

    printf("\nAge before update : %d\n", oldAge);
    printf("Age after update  : %d\n", person->age);

    if (person->age > 17)
        printf("WARNING: Adult privileges detected.\n");

    if (person->age > 18)
        printf("WARNING: Warranty has probably expired.\n");

    printf("Applying +1 year patch...\n");

    person->intelligence += 1;
    person->luck -= 1;

    printf("Intelligence +1\n");
    printf("Luck -1\n");

    printf("Patch completed successfully.\n");
}

void matrixEffect(void)
{
    char symbols[] = "| / - \\";
    
    for (int i = 0; i < 20; i++) {
        printf("\r[%c] Decrypting...", symbols[i % 7]);
        fflush(stdout);

        for (volatile long j = 0; j < 30000000; j++);
    }

    printf("\r                    \r");
}

void decodeMessage(void)
{
    /*
       The message is hidden through ASCII values.
       Because apparently a birthday message was
       not allowed to simply say "Happy Birthday".
    */

    int message[] = {
        72,97,112,112,121,32,
        66,105,114,116,104,100,97,121,33,32,
        89,111,117,39,114,101,32,
        111,108,100,32,110,111,119,46,32,
        71,111,111,100,32,
        108,117,99,107,32,
        119,105,116,104,32,
        121,111,117,114,32,
        107,110,101,101,115,46
    };

    int length = sizeof(message) / sizeof(message[0]);

    printf(">>> ");

    for (int i = 0; i < length; i++)
        putchar(message[i]);

    printf("\n");
}