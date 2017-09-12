#include<stdio.h>

int* return_arr(void)
{
	static int arr[3]={1,2,3};
	return arr;
}

int main()
{
int *arr_ptr;
arr_ptr=return_arr();
int i;

for(i=0;i<3;i++)
	printf("Array element %d is %d\n",i,*arr_ptr+i);
return;
}
