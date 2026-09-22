#include<stdio.h>
int main() {
    for(int i=1; i<=5; i++) {  // overall loop
        
        // Loop for left spaces 
        for(int s1=5-i; s1>0; s1--) {   
            printf(" ");
        }
        
        // Loop for numbers
        int num = i;
        // Part 1:
        for(int n=1; n<=i; n++) {
            printf("%i", num);
            num++;
        }
        
        // Part 2: 
        num -= 2; 
        for(int n=1; n<i; n++) {
            printf("%i", num);
            num--;
        }
	
        Loop for right spaces 
        for(int s2=5-i; s2>0; s2--) {   
        printf(" ");
	}
        
        printf("\n");
    }
    return 0;
}
