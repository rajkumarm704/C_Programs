#include<stdio.h>
int main()
{

	int n=0,mask=0,mask_copy=0,value;
	int hnum,i,position,position_copy,result;

	printf("Enter hex number: ");
	scanf("%x",&hnum);

	while(getchar() != '\n');	

	printf("Enter number of bits to get: ");
	scanf("%d",&n);

	while(getchar() != '\n');

	printf("Enter position of bits to get: ");
	scanf("%d",&position);
	
	while(getchar() != '\n');

	printf("Enter value: ");
	scanf("%x",&value);

	while(getchar() != '\n');

	position--;

	mask=((1<<n)-1)<<position;	

	mask_copy=mask;	
	mask=~mask;

	result=hnum&mask;
	value&=mask_copy;
	result=result|value;

	printf("Number is: %x\n",result);

	return 0;
}
