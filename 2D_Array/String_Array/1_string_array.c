#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");

	int i,j;
	char sarr[3][10] = { "raj", "kumar", "mishra" };
	
//	printf("%s\n%s\n%s\n",sarr[0], sarr[1], sarr[2] );
	printf("%s\n%s\n%s\n",sarr[0], sarr[1], sarr[2] );

	for( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < 10; j++ )
		{
			if( sarr[i][j] == '\0' )
				break;
			printf("%c, ", sarr[i][j] );
		}
		printf("\n");
	}

	return 0;

}
