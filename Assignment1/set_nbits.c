#include<stdio.h>
int main()
{

	int bit_set=0,mask=0,mask_2=0;
	int hnum,i,value,value_temp;
	printf("Enter hex number: ");
	scanf("%x",&hnum);

	while(getchar() != '\n');
	
	printf("Enter value: ");
	scanf("%x",&value);

	while(getchar() != '\n');
	
	printf("Enter number of bits to get: ");
	scanf("%d",&bit_set);

	while(getchar() != '\n');

	mask_2=((1<<bit_set)-1);	
	mask_2=~mask_2;
	mask=((1<<bit_set)-1);	
	
	hnum&=mask_2;	
	value_temp=value&mask;

	hnum |= value_temp;

	printf("Number is: %x\n",hnum);

	return 0;
}
