#include<stdio.h>
int main()
{

	int a,*p;
	a=9;
//	p=&a;
	p=&p;
	printf("a is %d, p is %p\n",a,p);

	*p=0x55;

	printf("a is %d, p is %p\n",a,p);
	
	printf("*&a is %d, &a is %p\n",*&a,&a);
	printf("*p is %d, address of &p is %p\n",*p,&p);

	return 0;
}
