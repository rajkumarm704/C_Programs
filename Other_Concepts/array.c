#include<stdio.h>
int main()
{

	int i,index;
	int arr[5] = { 2,5,8,9,6 };
	int arr_copy[5]={0,0,0,0,0};
//	arr_copy[1]=arr[1];
	index=5;
//	printf("Enter 5 elements: ");
	for(i=0;i<index;i++)
		scanf("%d",&arr[i]);
//		arr_copy[i]=arr[i];

//	index=99999;

	for(i=0;i<index;i++)
		printf("%d,  ",arr[i]);

		printf("\n");
	return 0;
}
