#include<stdio.h>

int main()
{
    int N;
    printf("how may numbers you wanna input : ");
    scanf("%i",&N);
    if (N<1)
    {
        printf("INVALID");
        return 1;
    }

    int inp[N];
    printf("INPUT : ");
    for (int i=0; i<N; i++)
    {
        scanf("%i",&inp[i]);
    }

    int maxdif = 0, max1, max2;
    for (int i=0; i<N-1; i++)
    {
        if(inp[i] < inp[i+1])
        {
            if(maxdif < inp[i+1]-inp[i])
            {
                maxdif = inp[i+1]-inp[i];
                max1 = inp[i];
                max2 = inp[i+1];
            }
        }
        else
        {
            if (maxdif < inp[i]-inp[i+1])
            {
                maxdif = inp[i]-inp[i+1];
                max1 = inp[i];
                max2 = inp[i+1];

            }
        }
    }
    printf("%i and %i difference = %i\n", max1, max2, maxdif);
    
    return 0;
