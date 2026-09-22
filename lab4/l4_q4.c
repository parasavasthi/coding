#include<stdio.h>

double prr (int pow, double base);

int main() {
    int x;
    
    printf("what is the value you want to find natural log of : ");
    scanf("%i",&x);

    double result = 0;
    double z = (double)(x - 1) / (x + 1);
    for (int i = 0; i<10; i++) {
        result = result + prr((2*i)+1,z)/((2.0*i)+1);
    }
    printf("the value of ln(%i) is %lf", x, result*2);
}

double prr(int pow, double base) {
    double result = 1;
    for (int i = 0; i<pow; i++) {
        result = result * base;
    }
    return result;
}