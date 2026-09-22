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

    int K;
    printf("how much position you wanna shift : ");
    scanf("%i",&K);
    if(K<0)
    {
        printf("INVALID");
        return 1;
    }
    K = K % N;

    printf("OUTPUT : ");
    for (int i=0; i<N; i++)
    {
        if(i<K)
        {
            printf("%i ",inp[N-K+i]);
        }
        else 
        {
            printf("%i ",inp[i-K]);
        }
    }
    return 0;
}