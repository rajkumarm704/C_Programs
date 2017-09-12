#include<stdio.h>
int y;
int sum(int x, int y)
{
	auto int r;
	r = x + y;
	return r;
}

int main()
{
	auto int z;
 	z = sum(20, 30);
	printf("Sum is %d\n",z);
	return 0;
}
