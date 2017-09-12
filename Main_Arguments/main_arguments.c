#include<stdio.h>				//Date:23rd June, 2017
#include<stdlib.h>

int main(int argc, char *argv[])
{
	system("clear");
	int idx;
	printf("Argument counter: %d\n", argc );
	
	for ( idx = 0; argv[idx] != NULL; idx++ )
	{
		printf("argv[%d]: %s\n",idx, argv[idx] );
		printf("argv[%d]: %c\n",idx, *( argv[idx] + 2) );
	}

	printf("Done\n");

//	printf("argv[%d]: %s\t",argc, argv[argc] );
//	printf("*argv[%d]: %c\n",argc, *argv[argc] );

	return 0;
}

/*

#include<stdio.h>				//Date:23rd June, 2017
#include<stdlib.h>

int main(int argc, char *argv[])
{
	system("clear");
	int idx;
	printf("Argument counter: %d\n", argc );
	
	for ( idx = 0; argv[idx] != NULL; idx++ )
	{
		printf("argv[%d]: %s\n",idx, argv[idx] );

		printf("*argv[%d]: %c\n",argc, *argv[argc] );
	}

//	printf("argv[%d]: %s\t",argc, argv[argc] );
//	printf("*argv[%d]: %c\n",argc, *argv[argc] );

	return 0;
}

*/
