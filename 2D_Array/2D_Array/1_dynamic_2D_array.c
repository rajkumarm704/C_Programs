//Number of columns are constant, rows are variable

#include<stdio.h>
#include<stdlib.h>

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

int main()
{
	system("clear");
	
	int i, j;
	int (*ptr)[3];	//arr[2][3]

	ptr = malloc( 2 * sizeof( *ptr ) );
	
	printf("Enter values:");

	for ( i = 0; i < 3; i++ )
		for( j = 0; j < 3; j++ )
			scanf("%d",&ptr[i][j] );


	print_2darray( ptr, 3, 3 );

	return 0;
}
