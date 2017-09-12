#include<stdio.h>

void print_arr(int *arr,int size)

{
	int i;
	printf("Array:\n");
	for(i=0;i<size;i++)
		printf("array[%d]:%d\n",i,arr[i]);
}



int main()
{	
	int size,i,k,temp;

	printf("Enter total number of elements:");
	scanf("%d",&size);
	int arr[size];
	i=0;
	temp=1;
	printf("Enter elements:");

	while(temp=(i++==size)?0:scanf("%d",&arr[i-1]));

	/*while(temp)
	{
		temp=(i++==size)?0:scanf("%d",&arr[i-1]);
		printf("Temp:%d,i:%d,k:%d\n",temp,i,k);
	}*/



//	for(i=0;i<size;i++)
//		scanf("%d",&arr[i]);


	print_arr(arr,size);
	return 0;
}
