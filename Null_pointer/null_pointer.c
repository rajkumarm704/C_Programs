#include<stdio.h>

void cne(void)
{
	system("clear");
	system("gcc null_pointer.c -o null_pointer.out");
}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}


void main()
{
	cne();
	ubound();

	int *ptr = NULL;
	char *cptr = '\0';
	
	printf("ptr:%p, cptr:%p\n",ptr,cptr);

	if(ptr != NULL)
		printf("Reading memory location pointed by ptr:%d\n",*ptr);
	
	else
		printf("Pointer is null. Assign a valid address to it.\n");

	lbound();
}
