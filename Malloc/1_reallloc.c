#include<stdio.h>
#include<stdlib.h>
int main()
{

	int *ptr;
	ptr = realloc(NULL,sizeof(int));

	printf("ptr = %p\n",ptr);
	if(ptr)
	{
		free(ptr);
		printf("Memory freed...\n");
	}

	return 0;
}
