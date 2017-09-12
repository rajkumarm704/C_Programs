#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>
#include<stdarg.h>

float elements(int count, ... )
{
	va_list ap;
	int i;
	va_start(ap, count);
	
	for(i = 0; i < count; i++ )
		printf( "%d ", va_arg(ap, int) );

	printf("\n");

	va_end(ap);

	return 0;
}


int main()
{
	system("clear");

	elements(5, 1, 2, 3, 4, 5);

	return 0;
}
