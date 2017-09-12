#include<stdio.h>				//Date:28th June, 2017
#include<stdlib.h>

int add(int x, int y)
{
	return x + y;
}

int main()
{
	system("clear");

	int (*a)(int, int);
	a = add;

	printf("Address of function: %p, %p, %p\n",add, &add, *add);
//	printf("Value of function: %d\n",add(2, 4));
	printf("Value of add function: %d\n",a(2, 8));

	return 0;
}
