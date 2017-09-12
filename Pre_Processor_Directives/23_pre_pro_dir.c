#include<stdio.h>
#include<stdlib.h>

#if defined (STATIC) || (DYNAMIC)
#define SIZE 100
#else
#error "Memory not allocated! Use either -D STATIC or DYNAMIC while compiling"
#endif

int main()
{
	system("clear");

#if defined STATIC
	char buffer[SIZE];
#elif defined DYNAMIC
	char *buffer = malloc(SIZE * sizeof(char) );
#endif

#if defined (STATIC) || (DYNAMIC)
	fgets(buffer, SIZE, stdin);
	printf("%s\n",buffer);
#endif

	return 0;
}

