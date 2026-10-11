#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    printf("what is the length of array: ");
    scanf("%d",&N);
    if(N<2||N>100) {
        printf("INVALID\n");
        return 1;
    }

    int *inp = (int *)malloc(N*sizeof(int));
    printf("INPUT: \n");
    for(int i=0; i<N; i++) {
        scanf("%d",(inp+i));
    }

    printf("output: \n");
    for(int i=N-1; i>=0; i--) {
        printf("%d ",*(inp + i));
    }
    free(inp);
    return 0;
}