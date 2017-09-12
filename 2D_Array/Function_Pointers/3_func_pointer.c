#include<stdio.h>				//Date:28th June, 2017
#include<stdlib.h>

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

void arithmatic( int (*func)(int, int), int a, int b)
{
	printf("\nResult\t:%d\n", func(a, b) );
}

int main()
{
	system("clear");

	arithmatic( add, 2, 3);
	arithmatic( sub, 1, 3);

	printf("\n");

	return 0;
}
