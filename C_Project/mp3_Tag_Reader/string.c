#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	system("clear");

	FILE *fp = NULL;
	char data[100];

	fp = fopen("new_file.txt", "w+" );

	sprintf(data, "*%-*s*\n", 20, "Raj Kumar");

	fwrite(data, 1, strlen(data), fp);
	
	fclose(fp);


	return 0;
}
