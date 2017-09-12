#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, limit, num;
	int *mptr;

	printf("Enter the number of elements:");
	scanf("%d",&limit);

	mptr = calloc(limit , sizeof(int));

	//Always place a check whether memory has been allocated or not.
	if( mptr)
	{
		for( i = 0; i < limit; i++)
		{
			printf("Dynamic address %d:%p\n", i, mptr+i);
		
		}

		for( i = 0; i < limit; i++)
		{
			printf("%d, ",*mptr++);
			fflush(stdout);
		}

		mptr = mptr - i;
		free(mptr);
		mptr = NULL;
	}

	printf("\n");

	return 0;
}

