#include<stdio.h>

//static int count;
int count;

static int counter(void)
{
	return ++count;
}

int func_2(void)
{
	printf("in %s counter is %d\n",__func__,counter());

	printf("In func_2 : address of %p\n",&count);
	return 0;
}
	
