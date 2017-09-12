#include<stdio.h>
#include<stdlib.h>

#define SIZE_1K 1024

int main( int argc, char *argv[])
{

	system("clear");

	FILE *fp1 = NULL, *fp2 = NULL, *fp3 = NULL;
	char buffer[SIZE_1K], ch;
	int i = 0;
	const char  *r = "r";
	const char  *wp = "w+";
	const char  *ap = "a+";

	if(argc == 1)
	{
		printf("Enter some characters. Press ctrl+D to stop\n");
		while( ( ch = getchar() ) != EOF )
		{
			buffer[i] = ch;
			i++;
		
			if(ch == '\n')
			{
				buffer[i] = '\0';
				printf("%s",buffer);
				i = 0;
			}	
		}
	}
	else if(argc == 2)
	{
		fp1 = fopen(argv[1],r);
		while( ( ch = fgetc(fp1) ) != EOF )
			printf("%c",ch);
		fclose(fp1);
	}
	else if(argc == 3)
	{
		fp1 = fopen(argv[1], r);
		fp2 = fopen(argv[2], wp);
		int size = fread( buffer, 1, 5000, fp1);
		fwrite( buffer, 1, size, fp2);
		fseek(fp2, 0l, SEEK_SET);
		while( ( ch = fgetc(fp2) ) != EOF )
			printf("%c",ch);

		fclose(fp1);
		fclose(fp2);
	}
	else if( argc == 4 )
	{
		fp1 = fopen(argv[1], r);
		fp2 = fopen(argv[2], r);
		fp3 = fopen(argv[3], ap);

		int size = fread( buffer, 1, 5000, fp1);
		fwrite( buffer, 1, size, fp3);

		size = fread( buffer, 1, 5000, fp2);
		fwrite( buffer, 1, size, fp3);

		fseek(fp3, 0l, SEEK_SET);
		while( ( ch = fgetc(fp3) ) != EOF )
			printf("%c",ch);

		fclose(fp1);
		fclose(fp2);
		fclose(fp3);


	}

	return 0;
}
