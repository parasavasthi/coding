#include<stdio.h>
int prr(int num, int pwr);
int main()
{
	int N, length = 0;
	printf("the number to test: ");
	scanf("%i",&N);
	
	//length of number
	int n = N; 
	if ( n == 0)
	{
		length = 1;
	}
	else {
	 	do {
	 		n = n/10;
			length++;
		}
		while(n != 0);
	}
	
	// sum of the digits of number with the power of the total numbers 
	int p=N;
	int sum = 0;
	for(int i = 0; i<length; i++)
	{
		sum += prr(p%10,length);
		p = p/10;
	}
	if (sum == N)
	{
		printf("number is armstrong number");
	}
	else 
	{
		printf("number is not armstrong number");
	}
	


	return 0;	
}


int prr(int num, int pwr)
{
	int r=1;
	for(int i=0; i<pwr; i++)
	{
		r *= num;
	}
	return r;
}