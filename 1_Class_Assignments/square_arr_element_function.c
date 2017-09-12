#include<stdio.h>

void square_arr(int *arr,int size)
{
	int i;
	printf("Original array:\n");
	for(i=0;i<size;i++)
	{
		printf("array[%d]:%d\n",i,arr[i]);
		arr[i]=arr[i]*arr[i];
	}
}

void print_arr(int *arr,int size)

{
	int i;
	printf("Squared array:\n");
	for(i=0;i<size;i++)
		printf("array[%d]:%d\n",i,arr[i]);
}



int main()
{	
	int size,i,result;

	printf("Enter total number of elements:");
	scanf("%d",&size);
	printf("Enter the elements:");

	int arr[size];

	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);


	square_arr(arr,size);
	print_arr(arr,size);
	return 0;
}
