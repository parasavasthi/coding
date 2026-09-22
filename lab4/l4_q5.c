#include<stdio.h>

int main() {
    int n;

    printf("how many prime number you want : ");
    scanf("%i",&n);

    int np = 0, i=2;
    while(np != n)
    {
        //check if i is prime
        int isprime = 1;
        for(int j=2; j*j<=i; j++) 
        {
            if(i%(j) != 0)
            continue;
            else
            {
            isprime = 0;
            break;
            }
        }
        if(isprime == 1)
        {
            printf("%i, ", i);
            np++;
        }
        i++;
    }
}