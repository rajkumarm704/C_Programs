#include<stdio.h>

double average(int *arr, int index)
{
	float sum=0;
	int i;
	for(i=0;i<index;i++)
		sum+=arr[i];

	return sum/index;
}

int main()
{
	int i,index=3;
	float avg=0;
	int arr[]= { 1,1,2 };
	avg=average(arr,index);
	printf("Average is %f\n",avg);

	return 0;
}
