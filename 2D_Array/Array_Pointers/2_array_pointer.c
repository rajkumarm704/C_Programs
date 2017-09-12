#include<stdio.h>
#include<stdlib.h>

//void print_array(int **p, int row, int col)	//valid
void print_array(int *p[], int row, int col)
{
	int i, j;

	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < col; j++ )
//			printf("%d ",p[i][j]);
			printf("%d ",*( p[i] + j ) );
		printf("\n");
	}
}



int main()
{
	system("clear");
	int i, row = 3, col = 3;
	int a[] = { 1, 2, 3};
	int b[] = { 4, 5, 6};
	int c[] = { 7, 8, 9};

	int *ptr[] = { a, b, c };

	print_array(ptr, row, col);

/*	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < col; j++ )
			printf("%d ", ptr[i][j]);
		printf("\n");
	}
*/

	printf("\n");

	return 0;
}
