#include<stdio.h>
#include<stdlib.h>

#define SWAP(a, b, type)	\
{				\
	type temp;		\
	temp = a;		\
	a = b;			\
	b = temp;		\
}


int main()
{
	system("clear");

	int a = 10, b = 20;
	float f1 = 2.5, f2 = 8.9;
	char c1 = 'A', c2 = 'Z';

	printf("a:%d, b:%d\n",a,b );		
	SWAP(a, b, int);
	printf("a:%d, b:%d\n\n",a,b );		

	printf("c1:%c, c2:%c\n",c1, c2 );		
	SWAP(c1, c2, char);
	printf("c1:%c, c2:%c\n\n",c1, c2 );		
	
	printf("f1:%.2f, f2:%.2f\n",f1, f2 );
	SWAP(f1, f2, float);
	printf("f1:%.2f, f2:%.2f\n\n",f1, f2 );		

	return 0;
}

