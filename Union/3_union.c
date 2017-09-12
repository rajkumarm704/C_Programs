#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

union Data
{
	int x;
	char c;
	double d;
}d1 = { .x = 65 };

int main()
{

	system("clear");


	void *vptr = malloc( 2 * sizeof(int) );
	*( (int *)vptr ) = 0x44434241;

	printf("Value of d1.x: %#x\n", *( (int *)vptr ) );
	printf("Value of d1.c: %c\n", *( (char *)vptr + 0) );
	printf("Value of d1.c: %c\n", *( (char *)vptr + 1) );
	printf("Value of d1.c: %c\n", *( (char *)vptr + 2) );


	return 0;
}
