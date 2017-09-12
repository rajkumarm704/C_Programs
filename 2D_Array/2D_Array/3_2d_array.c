#include<stdio.h>
int main()
{
	int i, j, rows = 2, cols = 3;
	int a[2][3] = { {1,2,3}, {4,5,6} };

	printf("\nIndex Notation\n");

	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )
			printf("%p ", &a[i][j] );
		printf("\n");
	}

	printf("\nPointer Notation\n");

	for( i = 0; i < rows; i++ )
	{
		for( j = 0; j < cols; j++ )
			printf("%p ", ( *( a + i ) + j ) );
		printf("\n");
	}

	printf("\n");

/*	printf("*(*( a + 1 ) + 1 ) = %d \n", *( *( a + 1 ) + 1 ) );
	a[i][j] = *(*( a + i ) + j )
	a[i] = *(a + i );
*/
	return 0;
}
