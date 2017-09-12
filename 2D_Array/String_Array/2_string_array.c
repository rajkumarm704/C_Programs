#include<stdio.h>
#include<stdlib.h>

void print_array(char *arr[], int size)
{
	int i;

	printf("\nIn function\n");

	for( i = 0; i < size; i++ )
		printf("%s\n",arr[i]);
}

int main()
{
	system("clear");

	int i,j;
	char *sarr[3];

	sarr[0] = "raj";
	sarr[1] = "kumar";
	sarr[2] = "mishra";

	printf("\nIn main function \n");
	printf("%s\n%s\n%s\n",sarr[0], sarr[1], sarr[2] );

	print_array( sarr, 3);

/*	for( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < 10; j++ )
		{
			if( sarr[i][j] == '\0' )
				break;
			printf("%c, ", sarr[i][j] );
		}
		printf("\n");
	}

*/
	return 0;

}
