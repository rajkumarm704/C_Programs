#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

	int i, j, rows, cols;
	int temp;

	printf("Enter number of rows and columns:");
	scanf("%d%d",&rows,&cols);
	int arr[rows][cols];
	
	printf("Enter %d elements\n", rows*cols);

	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )
			scanf("%d",&arr[i][j]);

	}

	printf("\n");
	
	printf("unsorted array\n");
	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )
			printf("%d\t", arr[i][j] );
		printf("\n");
	}

	printf("\n");


	for( i = 0; i < rows*cols; i++ )
	{
		for(j = 1; j < rows*cols; j++)
		{

			if( *(*arr + j - 1) > *(*arr + j) )
			{
				temp = *(*arr + j - 1);
				*(*arr + j - 1) = *(*arr + j);
				*(*arr + j) = temp;
			}

		}

	}

	printf("\nSorted array\n");
	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )
			printf("%d\t", arr[i][j] );
		printf("\n");
	}



		printf("\n");

	return 0;
}
