#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");

	printf("%d\n",SQUARE(2));
	printf("%d\n",SQUARE(3));
	return 0;
}

#define SQUARE(x) x * x
