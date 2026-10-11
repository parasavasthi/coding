#include<stdio.h>
#include<stdlib.h>

struct number {
    int val;
    int index;
};

int compare(const void* a, const void* b);

int main() {
    int inp_lng;
    printf("input length : ");
    scanf("%i",&inp_lng);

     if(inp_lng<2 || inp_lng>10000) {
        printf("invalid");
        return 1;
     }

    int* inp = (int*)malloc(inp_lng * sizeof(int));
    printf("Input : ");
    for(int i=0; i<inp_lng; i++) {

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

    struct number* arr = (struct number*)malloc(inp_lng * sizeof(struct number));

    for(int i=0; i<inp_lng; i++) {
        arr[i].val = inp[i];
        arr[i].index = i;
    }

    qsort(arr, inp_lng, sizeof(struct number), compare);

    int left = 0, right = inp_lng - 1, x = 1;

    while(left<right) {
        int current_sum = arr[left].val + arr[right].val;

        if(current_sum == trg) {
            printf("output : %i, %i", arr[left].index, arr[right].index);
            x = 0;
            break;
        }
        else if(current_sum > trg) {
            right--;
        }
        else {
            left++;
        }
    }

    if(x)
    {
        printf("no such pair");
        return 1;
    }
    return 0;
}

int compare(const void* a, const void* b) {
    return ((struct number*)a)->val - ((struct number*)b)->val;
}