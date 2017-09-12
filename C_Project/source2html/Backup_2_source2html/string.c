#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	system("clear");
	
	int char_count;
//	char str[0] = "/*\n//raj/*", *sptr;
	char *str, *sptr;
	FILE *fp = NULL;

	fp = fopen("test.c", "r" );
	fseek( fp, 0l, SEEK_END);
	char_count = ftell(fp);
	printf("char_count:%d\n", char_count);
	str = malloc(char_count * sizeof(char) );

	fseek( fp, 0l, SEEK_SET);

	fread(str, 1, char_count, fp);

	printf("\n################\ndata:%s\n################\n",  str);

	sptr = strstr(str, "/*");

	printf("\n################\nstring:%s\n################\n",  sptr);

	fclose(fp);

	return 0;
}
