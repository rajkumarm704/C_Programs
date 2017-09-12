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

int main()
{
	system("clear");

	int (*a[3])(int, int);
	a[0] = add;
	a[1] = sub;
	a[2] = mul;

	printf("Address of function: %p, %p, %p\n",add, &add, *add);
	printf("Value of add function: %d\n", a[0](2, 8));
	printf("Value of sub function: %d\n", (signed int)a[1](1, 4));
	printf("Value of sub function: %d\n", (unsigned int)a[1](1, 4));
	printf("Value of mul function: %d\n", a[2](3, 7));

	return 0;
}
