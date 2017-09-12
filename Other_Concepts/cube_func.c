#include<stdio.h>
int cube(int x)
{
	x=x*x*x;
	return x;
}

int main()
{
	int x=5;
	printf("Before call:%d\n",x);
	x=cube(x);
	printf("After call:%d\n",x);

	
	return 10;
}
