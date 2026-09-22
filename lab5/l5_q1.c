#include<stdio.h>

int main() 
{
    //how many int wanna store
    int N;
    printf("how much integer do you wanna add : ");
    scanf("%i",&N);
    if(N<1) {printf("invalid"); return 1;}
    //input the number array
    int inp[N];
    for(int i = 0; i<N; i++)
    {
        scanf("%i",&inp[i]);
    }
    for(int i = 0; i<N; i++)
    {
        int isnrep = 1;
        for(int j = 0; j<i-1; j++)
        {
            if(inp[i] == inp[j]) {isnrep=0; break;}
        }
        if (isnrep) {printf("%i ",inp[i]);}
    }
    return 0;
}