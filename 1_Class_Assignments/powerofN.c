#include<stdio.h>
int main()
{
	int num,num_copy,base;
	printf("Enter the base: ");	
	scanf("%d",&base);
	printf("\nEnter the number: ");	
	scanf("%d",&num);
	num_copy=num;
	int i,result,j;
	for(i=0;i<num;i++)
	{
	result=base;
		for(j=0;j<i;j++)
		{
			result=result*base;
		}
		printf("%d, ",result);
	}

}
