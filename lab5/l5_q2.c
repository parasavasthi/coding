#include<stdio.h>

int main() 
{
    //how many input values
    int N;
    printf("how may values you wanna input : ");
    scanf("%i",&N);
    if(N<1)
    {
        printf("INVALID\n");
        return 1;
    }

    //taking input 
    int inp[N];

    for (int i=0; i<N; i++)
    {
        scanf("%i",&inp[i]);
    }

    //taking the target value
    int trg;
    printf("what is the target value : ");
    scanf("%i",&trg);

    //checking and printing the desired output 

    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            if ( inp[i] + inp[j] == trg)
            {
                printf("%i + %i = %i\n", inp[i], inp[j], trg);
                break;
            }
        }
    }

}