#include<stdio.h>

void hpir(int n);

int main() 
{
   int height;
   printf("height: ");
   scanf("%i",&height);

   hpir(height);

}



void hpir(int n)
{
    if (n<=0)
    {
        return;
    }
    hpir(n-1);
    int p=n;
    for(int i=0; i<n; i++)
    {
        printf("%i",p);
        p++;
    }
    printf("\n");
}