#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *str = "Hello", *sdup;
	
	sdup = strdup(str);

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
