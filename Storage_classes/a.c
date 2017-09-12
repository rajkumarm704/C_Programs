#include<stdio.h>

//static int x ;
int x;

void print(void)
{
	x = 12;
	printf("printf function called externally\n");

}
