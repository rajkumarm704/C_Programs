#include<stdio.h>

int add_num(int a, int b)
{
	int s,z=10;
	s=a+b;
	
	printf("b=%d\n",b);
	printf("a=%d\n",a);

	printf("Address of b=%p\n",&b);
	printf("Address of a=%p\n",&a);
	printf("Address of s=%p\n",&s);
	printf("Address of z=%p\n",&z);

	return s;
}

int main()
{

	int y;

	printf("Address of y=%p\n",&y);
	y=add_num(5,4);

	printf("y=%d\n",y);
	return 0;
}
