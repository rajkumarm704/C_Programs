#include<stdio.h>
int main()
{

	int i,index=5;
	float sum=0;
	int arr[5];// = { 2,5,8,9,6 };

	printf("Enter 5 elements: ");

	for(i=0;i<index;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	sum/=index;
	printf("Average is %f  \n",sum);

	return 0;
}
