#include<stdio.h>
void func(int *x)
{
	*x=*x+1;

}

int main()
{
	int x=5;
	int *p;
	p=&x;
	printf("Before call:%d\n",x);
	func(p);
	printf("After call:%d\n",x);


	return 0;
}
