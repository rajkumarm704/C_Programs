#include<stdio.h>

extern int num;
//static int num;

int func_1()
{
	printf("num is %d from file2.\n",num);

	return 0;
}
