#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>

char *gptr;

void bye(void)
{
	printf("Bye Bye\n");
}

void exit_clean(void)
{
	printf("\nExiting main function\n");
	if(gptr)
	{
		free(gptr);
		printf("Memory is freed\n");
	}
}

int main()
{
	system("clear");
	gptr = malloc(100);
	char *ptr = "Hello";

	atexit(bye);
	atexit(exit_clean);	

	printf("Enter any string:");
	scanf("%[^\n]",gptr);
	printf("You have entered: %s",gptr);
	
	return 0;
}
