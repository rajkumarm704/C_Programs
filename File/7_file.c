/*	Open a file	*/

#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<err.h>

#define BUFF_1K 1024

int main(int argc, char *argv[] )
{

	system("clear");

	FILE *fp = NULL;
	char buff[BUFF_1K];
	int idx = 0, char_count = 0, line_count = 0;
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

		printf("Error! File %s could not be opened\n", argv[2] );
		return 2;
	}
	else
	{
		fseek(fp, 0l, SEEK_SET);
		ch = getc(fp);
		while(ch != EOF )
		{
			char_count++;
			buff[idx++] = ch;
			if( ch == '\n' )
				line_count++;
			ch = getc(fp);
		}
	}	
	
	printf("char_count:%d\nNumber of lines are: %d\nContent of File is\n\n", char_count, line_count);

	for( idx = 0; idx <= char_count; idx++)
		printf("%c",buff[idx]);

	printf("\n");

	fclose(fp);

	return 0;
}
