#include<stdio.h>
int main()
{
	int num,num_copy;
	printf("Enter the number: ");	
	scanf("%d",&num);
	num_copy=num;
	int i,result,j;
	for(i=0;i<num;i++)
	{
	result=2;
		for(j=0;j<i;j++)
		{
			result=result*2;
		}
		printf("%d, ",result);
	}

}
