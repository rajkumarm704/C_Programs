#include<stdio.h>

void init_arr(int **p, int size);
void print_arr(int *arr, int size);

int main()
{
	int arr[5] = {0,1,2,3,4};
	int *ptr = arr;
/*	printf("arr: %p\n",arr);
	printf("&ptr: %p\n",&ptr);
	printf("*ptr: %d\n",*ptr);
	printf("*&ptr: %p\n",*(&ptr));
	printf("**&ptr: %d\n",**(&ptr));
*/	init_arr(&ptr, 5);
	print_arr(arr, 5);
	
	return 0;
}

void init_arr(int **p, int size)
{
	int i;
	for ( i = 0; i < size; i++)
		(*p)[i] = i + 10;
//		*((*p)++) = i + 10;
//		*(*p + i) = 0;

}

void print_arr(int *arr, int size)
{
	int i;
	for ( i = 0; i < size; i++ )
		printf("%d ",arr[i]);

	printf("\n");
}
