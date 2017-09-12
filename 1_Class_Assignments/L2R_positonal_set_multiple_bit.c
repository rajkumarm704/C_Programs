#include<stdio.h>
int main()
{

	int bit_set=0,mask=0;
	int hnum,i,position;
	printf("Enter hex number: ");
	scanf("%x",&hnum);
	
	printf("Enter number of bits to set: ");
	scanf("%d",&bit_set);

	printf("Enter position of bits to set: ");
	scanf("%d",&position);

	mask=((1<<bit_set)-1)<<(position-bit_set+1);	

	hnum=hnum|mask;

	printf("Number is: %x\n",hnum);

	return 0;
}
