#include<stdio.h>

int main()
{
    int uplim, lowlim;

    printf("what is the upper limit in farenheit ");
    scanf("%i",&uplim);

    printf("what is the lower limit in farehanit ");
    scanf("%i",&lowlim);

    printf("farenheit   celsius\n");

    for(int i=0; i<(uplim-lowlim+1); i++)
    {
        printf("    %i       ",lowlim+i);
        float result= (5.0/9)*((lowlim+i)-32); 
        printf("%.2f  ",result);
        printf("\n");
    }
}