#include<stdio.h>
#include<stdlib.h>
int main()
{

	int *ptr;
	ptr = malloc(sizeof(int));

	printf("Address ptr = %p\n",ptr);

	ptr = realloc(ptr, 0);

	if(NULL == ptr)
		printf("Memory block freed, ptr:%p\n",ptr);
	else
		printf("Memory block could not be freed, ptr:%p\n",ptr);

	return 0;
}
