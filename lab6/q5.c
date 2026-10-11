#include<stdio.h>
#include<stdlib.h>

int main() {
    int *inp = (int *)calloc(10000, sizeof(int));
    printf("input: \n");
    while(1) {
        int temp;
        scanf("%d", &temp);

        if(temp>9999) {
            printf("invalid");
            return 1;
        }
        else if(temp>=0&&temp<10000){
        (*(inp+temp))++;
        }
        else if(temp<0) {
        break;
        }
    }
    
    printf("output: \nnumber     frequency\n");
    for(int i=0; i<10000; i++) {
        if(*(inp+i)){
            printf("%d           %d\n", i, *(inp+i)); 
        }
    }
}