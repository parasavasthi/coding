#include<stdio.h>
#include<stdlib.h>

int main() {
    int N;
    printf("waht is the length of input: ");
    scanf("%d",&N);
    if(N<1||N>100) {
        printf("invalid");
        return 1;
    }

    int *inp = (int *)malloc((N+1)*sizeof(int));
    printf("input: \n");
    for(int i=0; i<N; i++) {
        scanf("%d",(inp+i));
    }

    int K, E;
    printf("what is the value of input you wanna add to array: ");
    scanf("%d",&E);
    
    printf("where do you wanna place this new element: ");
    scanf("%d",&K);
    if(K<1||K>+N+1) {
        printf("invalid");
        return 1;
    }

    printf("before: \n");
    for(int i=0; i<N; i++){
        printf("%d ", *(inp+i));
    }

    int temp, temp1;
    for(int i=K-1; i<N+1; i++) {
        if(i == K-1) {
            temp = *(inp+i);
            *(inp+i) = E;
        }
        else {
            temp1 = *(inp+i);
            *(inp+i) = temp;
            temp = temp1;
        }
    }

    printf("\nafter: \n");
    for(int i=0; i<=N; i++) {
        printf("%d ", *(inp+i));
    }

    free(inp);
    return 0;
}