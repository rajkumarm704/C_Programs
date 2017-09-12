#include<stdio.h>
#include<stdlib.h>

#define SWAP(a, b)		\
{				\
	int temp = a;		\
	a = b;			\
	b = temp; 		\
}


int main()
{
	system("clear");

	int a = 10, b = 20;

	printf("a:%d, b:%d\n",a,b );		

	SWAP(a, b);
	printf("a:%d, b:%d\n",a,b );		

	SWAP(a, b);
	printf("a:%d, b:%d\n",a,b );		

	return 0;
}

