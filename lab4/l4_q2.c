#include<stdio.h>

int main()
{
    printf("the first five perfect numbers are: \n");
    int n = 0;
    int x = 4;
    
    while(n != 5)
    {
        int sum = 0;
        for (int i = 1; i * i <= x; i++)
        {   
            if (x % i == 0)
            {
                if (i == 1) {
                    sum += i; 
                } else if (i * i == x) {
                    sum += i; 
                } else {
                    sum += i + (x / i); 
                }
            }
        }

        if (sum == x)
        {
            printf("%d ", x);
            fflush(stdout);
            n++;
        }

        x++;
    }
    printf("\n");
    return 0;
}
