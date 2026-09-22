#include<stdio.h>
int main() {
	int h;
	printf("how much hight do you want to have for triangle: ");
	scanf("%i",&h);
	for (int l=1; l<=h; l++) {
		int x=l;
		for(int w=0; w<l; w++) {
			printf("%i ",x);
			x++;
		}
		printf("\n");
	}
	return 0;
}