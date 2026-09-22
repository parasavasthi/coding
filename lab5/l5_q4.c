#include<stdio.h>

int main()
{
    int N;
    printf("how may numbers you wanna input : ");
    scanf("%i",&N);
    if (N<3)
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

    int x=1;
    for (int i=1; i<N-1; i++)
    {
        if(inp[i-1] < inp[i] && inp[i] > inp[i+1])
        {
            printf("triplet %i: %i %i %i \n", x, inp[i-1], inp[i], inp[i+1]);
            x++;
        }
    }
    if (x == 0)
    {
        printf("no triplet found");
    }
    return 0;
}