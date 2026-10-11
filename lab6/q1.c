#include<stdio.h>
#include<stdlib.h>

void bsort(int *inp,int N);
int main() {
    int N1;
    printf("what is the length of input1: ");
    scanf("%d",&N1);
    if(N1<1||N1>100) {
        printf("INVALID; \n");
        return 1;
    }

    int *inp1 = (int *)malloc(N1 * sizeof(int));
    printf("INPUT1: \n");
    for(int i=0; i<N1; i++) {
        scanf("%d",(inp1+i));
    }
    
    int N2;
    printf("what is the length of input2: ");
    scanf("%d",&N2);
    if(N2<1||N2>100) {
        printf("INVALID; \n");
        return 1;
    }

    int *inp2 = (int *)malloc(N2 * sizeof(int));
    printf("INPUT2: \n");
    for(int i=0; i<N2; i++) {
        scanf("%d",(inp2+i));
    }

    bsort(inp1,N1);
    bsort(inp2,N2);

    printf("OUTPUT: \n");
    for(int i=0; i<N1; i++) {
        printf("%d, ",*(inp1+i));
    }
    
    printf("\n");

    printf("OUTPUT2: \n");
    for(int i=0; i<N2; i++) {
        printf("%d, ",*(inp2+i));
    }

    free(inp1);
    free(inp2);
    return 0;
}

void bsort(int *inp, int N) {   
    int temp;
    for(int i=0; i<N; i++) {
        int flag = 0;
        for(int j=0; j<N-i-1; j++) {
            if(*(inp+j)>*(inp+j+1)) {
                temp = *(inp+j);
                *(inp+j) = *(inp+j+1);
                *(inp+j+1) = temp;
                flag++;
            }
        }
        if(!flag) {           
            return;
        }
    }
}