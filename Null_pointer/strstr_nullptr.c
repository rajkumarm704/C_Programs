#include<stdio.h>

void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc strstr_nullptr.c -o strstr_nullptr.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}

#define STRING_SIZE 100

void main()
{
	cne();
	ubound();
	
	char string[STRING_SIZE] = "http://www.emertxe.com/Bangalore";
	char delimiter[4] = "p";
	char *cptr;

	cptr = strtok(string, delimiter);
	while(cptr != NULL)
	{
		printf("String is %s\n", cptr);
		cptr = strtok(NULL,delimiter);
	}
	
	lbound();
}
