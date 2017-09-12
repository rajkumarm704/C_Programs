#include<stdio.h>				//Date:28th June, 2017
#include<stdlib.h>

int compare_inc(int x, int y);
int compare_dec(int x, int y);
void swap(int *x, int *y);
void bubble_sort(int *arr, int size, int (*compare)(int, int) );
void print_array(int *arr, int size);

//Main Function
int main()
{
	system("clear");

	int numarr[] = { 20, -1, 50, 3, 100 };
	int size = (sizeof(numarr)/sizeof(int));
	
	bubble_sort(numarr, size, compare_inc);
	print_array(numarr, size);
	printf("\n");
	bubble_sort(numarr, size, compare_dec);
	print_array(numarr, size);
	printf("\n");
	return 0;
}


int compare_inc(int x, int y)
{
	return x > y;
}

int compare_dec(int x, int y)
{
	return x < y;
}

//Swap Function
void swap(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

//Bubble Sort
void bubble_sort(int *arr, int size, int (*compare)(int, int) )
{
	int i, j, temp, count = 0;

	for( i = 0; i < size - 1; i++ )
	{
		for( j = i; j < size - 1 ; j++ )
		{
//			printf("iterations:%d\n",count++ + 1);
			if( compare( arr[j], arr[j + 1] ) )
			{
				swap(&arr[j],&arr[j + 1]);
			}
		}
	}
}

//Print Array Function
void print_array(int *arr, int size)
{
	int i;

	for( i = 0; i < size; i++ )
		printf("%d ",arr[i]);

	printf("\n");
	
}

