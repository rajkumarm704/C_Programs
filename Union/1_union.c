#include<stdio.h>
#include<stdlib.h>

union Data
{
	int x;
	char c;
	double d;
}d1;

int main()
{

	system("clear");

	printf("Address of d1.x: %p\n", &d1.x );
	printf("Address of d1.c: %p\n", &d1.c );
	printf("Address of d1.d: %p\n", &d1.d );

	return 0;
}
