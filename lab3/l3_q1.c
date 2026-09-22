#include<stdio.h>
int main ()
{
	int N; //number of terms has to be shown of the series 
	printf("the number of terms displayed: ");
	scanf("%i",&N);
	
	int a=1; //the number of the series that will be shown
	
	for(int i=0; i<N; i++)
	{
		a += (2*i)+1;
		printf("%i, ",a);
	}
	return 0;
}	
		