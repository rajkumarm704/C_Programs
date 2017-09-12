#include<stdio.h>
int main()
{

	int bit_set=0,mask=0;
	int hnum,i;
	printf("Enter hex number: ");
	scanf("%x",&hnum);
	
	printf("Enter number of bits to set: ");
	scanf("%d",&bit_set);

	
//	for(i=0;i<bit_set;i++)
//		mask|=1<<i;

	mask=(1<<bit_set)-1;	

	hnum=hnum|mask;

	printf("Number is: %x\n",hnum);

	return 0;
}
