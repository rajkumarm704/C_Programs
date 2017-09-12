#include<stdio.h>

float average_arr(int *arr,int size)
{
	int i;	
	float average=0;
	for(i=0;i<size;i++)
	{
		printf("array[%d]:%d\n",i,arr[i]);
		average=average+arr[i];
	}
	average/=size;
	return average;

}



int main()
{	
	int size,i;
	float result;

	printf("Enter total number of ekements:");
	scanf("%d",&size);
	printf("Enter the elements:");

	int arr[size];

	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);


	result=average_arr(arr,size);
	printf("The average is:%f\n",result);
	return 0;
}
