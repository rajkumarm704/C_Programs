#include<stdio.h>
int main()
{
	const int i;
//	i = 10;
	printf("i:%d, Address of i:%p\n", i, &i);
	return 0;
}
