#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<err.h>

#define BUFF_1K 5000

int main(int argc, char *argv[] )
{

	system("clear");

	FILE *fp1 = NULL, *fp2 = NULL;
	const char *r = "r";
	const char *w = "w";
	char buff[BUFF_1K];
	int idx = 0, char_count = 0, line_count = 0;
	char ch;

	if( argc < 3)
	{
		printf("Invalid arguments\n");
		return 1;
	}



	//Open source file and read the contents
/*********************************************************/
	fp1 = fopen(argv[1], r);	//Source File

	if( NULL == fp1 )
	{
		perror("");
		printf("Error! File %s could not be opened\n", argv[2] );
		return 2;
	}
	else
	{
		fseek(fp1, 0l, SEEK_SET);
		ch = getc(fp1);
		while(ch != EOF )
		{
			char_count++;
			buff[idx++] = ch;
			ch = getc(fp1);
		}
	}	
/*********************************************************/

	//Create and Open Destination file to write the source content here
/*********************************************************/
	fp2 = fopen(argv[2], w);	//Destination File

	fseek(fp2, 0l, SEEK_SET);

	for( idx = 0; idx < char_count; idx++)
		fputc(buff[idx], fp2);
/*********************************************************/

	printf("Operation completed successfully.\n");

	//Close the files
	fclose(fp1);
	fclose(fp2);

	return 0;
}

