#include<stdio.h>
#include<stdlib.h>

typedef int func_t(int, int);

int add( int x, int y)
{
	return x + y;
}

int sub( int x, int y)
{
	return x - y;
}


int main()
{

	system("clear");

	func_t *f;

	f = add;
	printf("%d\n", f(2 ,3) );

	f = sub;
	printf("%d\n", f(2 ,3) );

	return 0;
}
