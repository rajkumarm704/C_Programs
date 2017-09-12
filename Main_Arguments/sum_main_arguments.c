#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	system("clear");

	int idx, sum = 0;
	printf("Argument counter: %d\n", argc );
	
	for ( idx = 1; argv[idx] != NULL; idx++ )
	{
		sum += atoi(argv[idx]);
		printf("argv[%d]: %s\n",idx, argv[idx] );
	}

	printf("sum: %d\n",sum );

	return 0;
}
