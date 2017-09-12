#include<stdio.h>
#include<stdlib.h>

union Data
{
	int x;
	char c;
	double d;
}d1 = { .x = 0x44434241 };

/*
union Data
{
	int x;
	char c;
	double d;
}d1;// = { .x = 0x44434241, .c = 'E' };
*/

int main()
{

	system("clear");

//	d1.x = 0x44434241;
	printf("Value of d1.x: %#x\n", d1.x );
	printf("Value of d1.c: %c\n", d1.c );

	d1.c = 'F';
	printf("Value of d1.x: %#x\n", d1.x );
	printf("Value of d1.c: %c\n", d1.c );

	printf("Value of d1.d: %f\n", d1.d );

	return 0;
}
