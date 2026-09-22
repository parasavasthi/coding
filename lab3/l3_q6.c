#include<stdio.h>
int main()
{
    int base, power, result=1;

    printf("what is the base ");
    scanf("%i",&base);

    printf("what is the power ");
    scanf("%i",&power);

    for(int i=0; i<power; i++)
    {
        result = result*base;
    }

    printf("the result is %i", result);

    return 0;
}