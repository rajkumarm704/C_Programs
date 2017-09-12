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
		int idx = 0, char_count = 0;
		char ch;
		size_t size;

		printf("Write your message here. Press Ctrl + D to exit.\n");
		while(1)
		{
			if( (ch = getchar() ) != EOF )
			{
				buff[idx++] = ch;
				char_count++;
			}
			if( ch == '\n' || ch == EOF ) 
			{
				if(char_count)
				{
					size = fwrite(  buff, 1, char_count, fp);
					printf("Size: %ld, char_count: %d\n", size, char_count);
				}
				char_count = 0;
				idx = 0;
				if( ch == EOF )
					break;
			}
		}
		/*	read test	*/
		{
			int ch;

			fseek(fp, -2l, SEEK_CUR);
			ch = getc(fp);
			if(ch != -1)
				printf("Character read is %c\n", ch);
			else
				printf("Error...Read Failure\n");
		}
	}	

	printf("Message saved\n");

	fclose(fp);

	return 0;
}
