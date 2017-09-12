#include<stdio.h>
int main()
{

	int bit_set=0;
	int hnum;
	printf("Enter hex number: ");
	scanf("%x",&hnum);
	
	printf("Enter bit to set: ");
	scanf("%x",&bit_set);

	hnum=hnum|(1<<bit_set);

	printf("Number is: %x\n",hnum);

	return 0;
}
