#include<stdio.h>
int main()
{
	int x = 10;
	int *ptr1, **ptr2;
	ptr1 = &x;
	ptr2 = &ptr1;

	printf("&x\t\t:%p\n",&x);
	printf("ptr1\t\t:%p\n",ptr1);
	printf("*ptr2\t\t:%p\n",*ptr2);

	printf("x\t\t:%d\n",x);
	printf("*ptr1\t\t:%d\n",*ptr1);
	printf("**ptr2\t\t:%d\n",**ptr2);

	printf("**ptr2+1\t:%d\n",**ptr2+1);
	printf("x\t\t:%d\n",x);
	printf("++**ptr2+1\t:%d\n",++**ptr2);
	printf("x\t\t:%d\n",x);

	return 0;
}
