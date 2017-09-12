#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[3], int size)
{
	int i;
	for( i = 0; i < size; i++ )
		printf("%d ",arr[i] );
	
	printf("\n");
}

void print_2darray(int (*arr)[3], int rows, int cols)
{
	int i, j;

	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )		
			printf("%d ",arr[i][j] );
		printf("\n");
	}
	printf("\n");
}

/*	Working
void print_2darray(int arr[2][3], int rows, int cols)
{
	int i, j;
	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )		
			printf("%d ",arr[i][j] );
		printf("\n");
	}
}
*/

int main()
{
	system("clear");

	int arr[3] = { 1, 2, 3 };

	int i, j;
	int rows = 2, cols = 3;
	int a[2][3] = { {10 ,20 ,30 }, {40, 50, 60 } };
	int (*b)[3] ;

	b = a;

/*	printf("b\t:%p\n",b );
	printf("*b\t:%p\n",*b );
	printf("**b\t:%d\n",**b );
*/

/*	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )		
			printf("%d ",b[i][j] );
		printf("\n");
	}
	printf("\n");
*/

//	print_array(arr, 3);
	print_2darray(a, rows, cols);	
//	print_2darray(b, rows, cols);

	return 0;
}
