#include<stdio.h>
int main()
{

	int n=0,mask=0,mask_copy=0,value;
	int hnum,i,position,position_copy,result;
/**/
	printf("Enter hex number: ");
	scanf("%x",&hnum);

	while(getchar() != '\n');	
/**/
	printf("Enter number of bits to toggle: ");
	scanf("%d",&n);

	while(getchar() != '\n');
/**/
	printf("Enter position of bits to toggle: ");
	scanf("%d",&position);
	
	while(getchar() != '\n');
/**/
	position--;
	mask=((1<<n)-1)<<position;	
	printf("mask %x\n",mask);

	mask_copy=mask;	
	printf("mask copy %x\n",mask_copy);
//	mask=~mask;

	printf("hnum %x\n",hnum);

	printf("mask %x\n",mask);
	result=hnum^mask;

	printf("Number is: %x\n",result);

	return 0;
}
