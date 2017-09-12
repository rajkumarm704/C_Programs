#include<stdio.h>

//static int x;
int x ;

void print1(void)
{
	x = 99;
	printf("printf function 1 called externally\n");
}
