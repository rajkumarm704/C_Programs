#include<stdio.h>
#include<stdlib.h>

#define SQUARE(x) (x) * (x)

int main()
{
	system("clear");

	int a = 2, b = 2, res;
	res = SQUARE(a + b);
	printf("Result is %d\n",res);

	return 0;
}

