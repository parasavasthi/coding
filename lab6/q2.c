#include<stdio.h>
#include<stdlib.h>

void bsort(int *inp, int N);
int comp(int *inp1,int n1, int *inp2, int n2);
void prt(int*inp, int n);

int main() {
    int N1, N2;
    printf("what is the length of input1: ");
    scanf("%d",&N1);
    if(N1<1||N1>100) {
        printf("invalid");
        return 1;
    }

    int *inp1 = (int *)malloc(N1*sizeof(int));
    printf("INPUT1: \n");
    for(int i=0; i<N1; i++) {
        scanf("%d", (inp1+i));
    }

    printf("what is the length of input2: ");
    scanf("%d", &N2);
    if(N2<0||N2>100) {
        printf("invalid");
        return 1;
    }

    int *inp2 = (int *)malloc(N2*sizeof(int));
    printf("INPUT2: \n");
    for(int i=0; i<N2; i++) {
        scanf("%d", (inp2+i));
    }

    bsort(inp1, N1);
    bsort(inp2, N2);

    printf("OUTPUT1: \n");
    prt(inp1, N1);

    printf("OUTPUT2: \n");
    prt(inp2, N2);

    int dif = comp(inp1, N1, inp2, N2);

    if(!dif) {
        printf("the two arrays are identical, the distinct elements are 0.\n");
    }
    else if(dif == -1) {
        printf("the two arrays are of different sizes therefore incomparable.\n");
    }
    else {
        printf("the two arrays are not totally identical, the distinct elements are %d.\n",dif);
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

int comp(int *inp1,int n1, int *inp2, int n2) { //returns the number of different figures in sorted arrays and returns -1 when arrays are non-comparable aka do not have same size
    int dif=0;
    if(n1 != n2)
        return -1;
    
    for(int i=0; i<n1; i++) {
        if(*(inp1+i) != *(inp2+i)) {
            dif++;
        }
    }

    return dif;
}

void prt(int*inp, int n) {
    for(int i=0; i<n; i++) {
        if(i<n-1)
        printf("%d, ",*(inp+i));
        else
        printf("%d",*(inp+i));
    }
    printf("\n");
    return;
}