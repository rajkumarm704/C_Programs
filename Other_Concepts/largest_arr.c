#include<stdio.h>
int main()
{

	int i,index=5,greater=0,j;
	float sum=0;
	int arr[5];// = { 2,5,8,9,6 };

	printf("Enter 5 elements: ");

	for(i=0;i<index;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i=0;i<index;i++)
		greater=greater>arr[i]?greater:arr[i];

	printf("Greater number is %d  \n",greater);

	return 0;
}
