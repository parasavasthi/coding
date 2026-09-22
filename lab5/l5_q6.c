#include<stdio.h>

int main()
{
    int N;
    printf("how may numbers you wanna input : ");
    scanf("%i",&N);
    if (N<2)
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

    int lngf=0, lngi=1, maxf;
    for (int i=0; i<N-1; i++)
    {
        if(inp[i] < inp[i+1])
        {
            lngi++;
        }
        if(inp[i] > inp[i+1])
        {
            if(lngi > lngf)
            {
                lngf = lngi;
                maxf = i;
            }
            lngi = 1;
        }
    }

    for(int i=0; i<lngf; i++)
    {
        printf("%i ", inp[maxf-lngf+1+i]);
    }
    printf("\nLength = %i", lngf);

    return 0;
}