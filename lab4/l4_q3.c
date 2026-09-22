#include<stdio.h>

double prr(int pw, double base);      //make a prr function

int fact(int num);      //make function for factorial

int main() {
    int degree;

    printf("what is the degree you want to find the value of sine for: ");
    scanf("%i",&degree);

    //find the radians 
    double rad = 3.14 * degree * (1.0/180);

    double result = 0.00;
    for(int i =0; i<10;i++)
    {
    if (i % 2 == 0)
        result = result + prr((2*i)+1, rad) / fact((2*i)+1);
    else
        result = result - prr((2*i)+1, rad) / fact((2*i)+1);    
    }

    printf("\nthe value of sin(%i) is %lf",degree, result);

}

double prr(int pw, double base)
{
    double result = 1;
    for(int i=0; i<pw; i++)
    {
        result = result * base;
    }
    return result;
}

int fact(int num)
{
    int result = 1;
    for(int i=0; i<num; i++)
    {
        result = result * (num -i);
    }
    return result;
}