    #include<stdio.h>
    #include<stdlib.h>

    void bsort(int *inp, int N);
    int *merg(int *inp1,int n1, int *inp2, int n2, int *merg_size);
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

        int m;
        int *merged = merg(inp1, N1, inp2, N2, &m);

        printf("merged array: \n");
        prt(merged, m);

        free(merged);
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

    int *merg(int *inp1,int n1, int *inp2, int n2, int *merg_size){
        int *result = (int *)calloc(n1+n2, sizeof(int));
        int a1=0, a2=0, r=0;
        while(a1!=n1&&a2!=n2) {
            if(*(inp1+a1)<*(inp2+a2)) {
                *(result+r) = *(inp1+a1);
                r++;
                a1++;
            }
            else if(*(inp1+a1)>*(inp2+a2)) {
                *(result+r) = *(inp2+a2);
                r++;
                a2++;
            }
            else {
                *(result+r) = *(inp1+a1);
                r++;
                a1++;
                a2++;            
            }
        }
        while (a1 != n1) {
        *(result + r) = *(inp1 + a1);
        r++; a1++;
        }
        while (a2 != n2) {
        *(result + r) = *(inp2 + a2);
        r++; a2++;
        }
        result = realloc(result, r*sizeof(int));
        *merg_size = r;
        return result;
    }


    void prt(int *inp, int n) {
        for(int i=0; i<n; i++) {
            if(i<n-1)
            printf("%d, ",*(inp+i));
            else
            printf("%d",*(inp+i));
        }
        printf("\n");
        return;
    }