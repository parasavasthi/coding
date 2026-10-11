#include <stdio.h>

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int result[N];
    int j = 0; // Index to track the position in the result array

    for (int i = 0; i < N; i++) {
        int isDuplicate = 0;
        for (int k = 0; k < j; k++) {
            if (arr[i] == result[k]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            result[j++] = arr[i];
        }
    }

    printf("Resulting array after removing duplicates:\n");
    for (int i = 0; i < j; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
