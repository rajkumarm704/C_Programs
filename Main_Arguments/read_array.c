#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

	int i, j, rows, cols;

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
	
	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )
			printf("%d\t", arr[i][j] );
		printf("\n");
	}


	printf("\n");
	return 0;
}
