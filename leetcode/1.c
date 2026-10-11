#include<stdio.h>

int main () {
    int N;
    printf("length of input : ");
    scanf("%i",&N);

    if(N<2 || N>10000) {
        printf("invalid");
        return 1;
    }

    int inp[N];
    printf("Input : ");
    for(int i=0; i<N; i++) {
        scanf("%i",&inp[i]);
        if(inp[i]<(-1000000000) || inp[i]>1000000000) {
            printf("invalid");
            return 1;
        }
    }

    int trg;
    printf("target value : ");
    scanf("%i",&trg);

    if(trg<(-1000000000) || trg>1000000000) {
        printf("invalid");
        return 1;
    }

    printf("Output : ");
    int x=0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(inp[i]+inp[j] == trg) {
                printf("[%i,%i]", i, j);
                x++;
                break;
            }
        }
        if(x) {
            break;
        }
    }

}