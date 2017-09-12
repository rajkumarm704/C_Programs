#include<stdio.h>
int func(int x)
{
	x=x+1;
	return x;
}

int main()
{
	int x=5;
	printf("Before call:%d\n",x);
	x=func(x);
	printf("After call:%d\n",x);


	return 0;
}
