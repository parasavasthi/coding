#include<stdio.h>

int main() {
    int n;

    printf("how many hexagonal number you want to be printed : ");
    scanf("%i",&n);

    for(int i=1; i<=n; i++) {
        printf("%i, ", i*((2*i)-1));
    }
}