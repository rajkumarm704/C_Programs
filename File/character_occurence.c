#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<err.h>


int main(int argc, char *argv[] )
{

	system("clear");

	FILE *fp = NULL;
	const char *r = "r";
	char ch;

	if( argc < 3)
	{
		printf("Invalid arguments.\nPlease execute in following format.\ncommand <file name> <character to find>\n\n");
		return 1;
	}

	fp = fopen(argv[1], r);

	if( NULL == fp )
	{
		perror("");
		printf("Error! File %s could not be opened\n", argv[1] );
		return 2;
	}
	else
	{
		ch = fgetc(fp);
		while( ch !=  *argv[2] )
			ch = fgetc(fp);

		printf("Position of %c is %ld\n", *argv[2], ftell(fp) );
	}

	
	fclose(fp);

	return 0;
}
