#include<stdio.h>

int main()
{
	int i = 10;
	static int z = i;

	printf("Value of z is %d\n",z);
	return 0;
}
