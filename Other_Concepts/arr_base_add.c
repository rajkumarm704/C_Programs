#include<stdio.h>
int main()
{
	int arr[9]={1,2,3,4,5,6,7,8,9};
	int *ptr;
	ptr=arr;	//No need to use '&' operator in case of arrays
	printf("Base address of array is %p\n",arr);
	printf("Size of array:%d\n",sizeof(arr));
	printf("Size of address array:%d\n",sizeof(&arr));
	printf("Base address of array using pointer:%p\n",ptr);
	int i;

	for(i=0;i<9;i++)
		printf("Element %d is %d.\n",i,*ptr+i);

	for(i=0;i<9;i++)
		printf("Address of element %d of array is %p\n",i,ptr+i);


	return 0;
}
