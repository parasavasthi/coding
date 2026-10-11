#include<stdio.h>
#include<stdlib.h>

int main()
{
    /*You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

    Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1. */


    int N;

    printf("how many numbers you wanna input : ");
    scanf("%i",&N);

    if(N<1)
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

    int x;

    printf("what is the target value : ");
    scanf("%i",&x);

    int n = x, ia=0, ib=0, count=0;
    while(n!=0 || n>0)
    {
        if(abs(n-inp[1+ia]) < abs(n-inp[N-ib]))
        {
            n = n - inp[1+ia];
            ia++;
            count++;
        }
        else 
        {
            n = n - inp[N-ib];
            ib++;
            count++;
        }

    }

    printf("OUTPUT : ");
    if(n==0)
    {
        printf("%i",count);
    }
    else
    {
        printf("-1");
    }

    return 0;
}