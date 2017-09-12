/*	Open a file	*/

#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<err.h>

/* use different options to open file
r	: Read Only
r+	: Read and edit
w	: Create and write
w+	: Create and write
a	: Append, create if file ddoes not exist
a+	: Append, create if file ddoes not exist

*/

int main(int argc, char *argv[] )
{

	system("clear");

	FILE *fp = NULL;
	char ch;

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
//		perror("fopen");
		printf("Error! File %s could not be opened\n", argv[2] );
		return 2;
	}

	fseek(fp, 2l, SEEK_CUR );
	ch = fgetc( fp );

	if( ch != -1 )
		printf("%c\n",ch);
	else
		printf("Error... Read Failure\n");


	fclose(fp);

	return 0;
}
