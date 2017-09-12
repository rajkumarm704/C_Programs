#include<stdio.h>
int main()
{

	int n=0,mask=0,iter=0;
	int hnum,i,position,position_copy,result;

	printf("Enter hex number: ");
	scanf("%d",&hnum);
	
	printf("Enter number of bits to get: ");
	scanf("%d",&n);
//	n--;
	printf("Enter position of bits to get: ");
	scanf("%d",&position);
	
	position_copy=position;
	position--;

	iter=position*n;
	mask=((1<<n)-1)<<iter;	


//	mask=mask<<iter;

	result=hnum&mask;
	result=result>>(iter);

	printf("Number is: %d\n",result);

	return 0;
}
