//DOUBT: HOW TO FIND OUT THE NUMBER OF ELEMENTS OF AN ARRAY IN FUNCTION WHEN AN ARRAY IS PASSED TO FUNCTION.	***CLARIFIED***

#include<stdio.h>

//void print_arr(int arr[])	//arr[] is not array. It is adjusted pointer
void print_arr(int *arr)	//Both will work. We never pass array in function call. We only 				//pass base address of array.
//void print_arr(int *p)
{
	int i,limit;
	//limit=(sizeof(arr+1)/sizeof(int));
	//printf("Limit:%d\n",limit);
	for(i=0;i<5;i++)
//		printf("array[%d]:%d\n",i,*arr++);	//Both will work
		printf("array[%d]:%d\n",i,arr[i]);
}



int main()
{
int arr[5]={1,2,3,4,5};
int *ptr;
ptr=arr;
print_arr(arr);
return 0;
}
