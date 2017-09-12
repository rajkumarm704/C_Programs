#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<err.h>

int main(int argc, char *argv[] )
{

	system("clear");

	FILE *fp = NULL;

	if( argc < 3)
	{
		printf("Invalid aarguments\n");
		return 1;
	}

	printf("File to be opened: %s\n", argv[2]);
	printf("Mode of open: %s\n", argv[1]);

	fp = fopen(argv[2], argv[1]);

	if( NULL == fp )
	{
		perror("");
		printf("Error! File %s could not be opened\n", argv[2] );
		return 2;
	}
	else
		printf("File was opened successfully but you didn't perform any operation ;-P\n");

	fclose(fp);

	return 0;
}
