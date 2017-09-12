#include<stdio.h>
#include<stdlib.h>

int main()
{
	int  *ptr, *nptr = NULL, i;

	ptr = (int *) malloc(5 * sizeof(int));

	if( NULL == ptr )
	{
		fprintf(stderr,"malloc:Memory not allocated\n");
		return 1;
	}

	for( i = 0; i < 5; i++ )
		ptr[i] = i + 10;


#if 1
	nptr = realloc(ptr, 100000 * sizeof(int));
#else
	nptr = realloc( ptr, 10 * sizeof(int));
#endif

	if( NULL == nptr )
	{
		fprintf(stderr,"realloc:Memory not allocatedd\n");
		free(ptr);
		return 2;
	}

	printf("ptr:%p, nptr:%p\n", ptr, nptr);

	if( (nptr != ptr ) && (nptr != NULL))
	{
		printf("Old and new addresses are different\n");
	
		for( i = 0; i < 10; i++ )
			printf("nptr[%d]:%d\n", i, nptr[i]);

	}
	else if( nptr == ptr)
	{
		printf("Old and new addresses are same.\n");
			for( i = 0; i < 10; i++ )
			printf("nptr[%d]:%d\n", i, nptr[i]);
	}

	if(nptr != NULL)
		ptr = nptr;

	free(ptr);

	return 0;

}	










