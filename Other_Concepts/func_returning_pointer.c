#include<stdio.h>
int* num(void)
{
//	static int x;
	int x;
	x=10;
	return &x;
}

int main()
{

int *ptr;
ptr=num();
//while(0);
printf("Yoo.\n");
printf("After function call num is: %d.\n",*ptr);
return 0;
}
