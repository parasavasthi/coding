#include<stdio.h>

int main() 
{
    //find the number of rows and column for the first matrix
    int c_a, r_a;
    printf("what are the dimentions for matrix one : ");
    scanf("%i %i", &r_a, &c_a);

    // take the input in array made for matrix a
    int a[r_a][c_a];
    printf("enter the values of matrix a : \n");

    for(int i=0; i<r_a; i++)
    {
        for(int j=0; j<c_a; j++)
        {
            scanf("%i",&a[i][j]);
        }
    }

    //find the number of rows and column for the second matrix
    int c_b, r_b;
    printf("what are the dimentions for matrix two : ");
    scanf("%i %i", &r_b, &c_b);

    //check the compatibility of both 
    if (c_a != r_b)
    {
        printf("matrices can not be multiplied");
        return 1;
    }

    // take the input in array made for matrix b
    int b[r_b][c_b];
    printf("enter the values of matrix b : \n");

    for(int i=0; i<r_b; i++)
    {
        for(int j=0; j<c_b; j++)
        {
            scanf("%i",&b[i][j]);
        }
    }

    //multiply the matrices 
    int c[r_a][c_b];

    //initialisation of matrix c
    for(int i = 0; i < r_a; i++) 
    {
        for(int j = 0; j < c_b; j++) 
        {
          c[i][j] = 0;
        }
    }

    //maths of matrix
       for(int i = 0; i < r_a; i++)
    {
        for(int j = 0; j < c_b; j++)
        {
            for(int k = 0; k < c_a; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    //print the resultant matrix
    printf("the resultant matrix is :\n");
    for(int i=0; i<r_a; i++)
    {
        for(int j=0; j<c_b; j++)
        {
            printf("%i ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}