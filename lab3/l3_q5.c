#include<stdio.h>
int main() {
	int n, l ;
	printf("what is the number? ");
	scanf("%i",&n);
	int N1=n, sum=0, N2=n;
	
	while(N1/10 !=0) {
		l=0;
		sum=0;
		//length of number 
		while(N1!=0) {
			N1 = N1/10;
			l++;
		}
	
		//sumation of digits
		for(int i=0; i<l; i++) {
			sum += (N2%10);
			N2 = N2/10;
		}
		N1=sum;
		N2=sum;
	}
	printf("%i",N1);
	return 0;
}
	