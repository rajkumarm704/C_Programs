#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *strdup_func(const char *str)
{
	char *mptr;
	int i;

	mptr = malloc( strlen(str) + 1 );

	if(mptr)
	{	
		for( i = 0; i < strlen(str) ; i++ )
			mptr[i] = str[i];

		mptr[ i + 1 ] ='\0';
	}
	else
		printf("Memory full. Try later.\n");

	return mptr;

}

int main()
{
	char *str = "Hello", *sdup;
	char str1[5] = "raj";

	sdup = strdup_func(str1);	
//	sdup = strdup_func(str);

	if( sdup )
	{
		printf("Duplicate string:%s\n",sdup);
		free(sdup);
		printf("Memory freed.\n");
	}
	else
		printf("Could not duplicate.\n");

	return 0;
}
