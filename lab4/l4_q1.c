#include <stdio.h>

int main()
{
    int limlow, limhigh;

    printf("what is the value of lower lim: ");
    scanf("%i", &limlow);

    printf("what is the value of upper lim: ");
    scanf("%i", &limhigh);

    int total_primes = 0;

    printf("\nThe prime numbers between %d and %d are:\n", limlow, limhigh);

    int n = limlow;
    for (int i = 0; i < limhigh - limlow + 1; i++)
    {
        int is_prime = 1; 

        if (n <= 1) {
            is_prime = 0;
        }

        for (int j = 2; j * j <= n; j++) 
        {
            if (n % j == 0)
            {
                is_prime = 0; 
                break;        
            }
        }

        if (is_prime == 1) {
            printf("%d ", n); 
            total_primes++;
        }

        n++; 
    }

    printf("\n\nThe total number of prime numbers are: %d\n", total_primes);

    return 0;
}



