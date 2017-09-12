#include<stdio.h>
int add(int x,int y)
{
	x=x+y;
	return x;
}

int main()
{
	int x=5,y=50;
	printf("Before call x:%d y:%d\n",x,y);
	x=add(x,y);
	printf("Sum is:%d\n",x);
	return 0;
}
