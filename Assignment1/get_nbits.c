#include<stdio.h>
int main()
{

	int bit_set=0,mask=0;
	int hnum,i,position;
	printf("Enter hex number: ");
	scanf("%d",&hnum);
	
	printf("Enter number of bits to get: ");
	scanf("%d",&bit_set);

	mask=((1<<bit_set)-1);	

	hnum=hnum&mask;

	printf("Number is: %d\n",hnum);

	return 0;
}
