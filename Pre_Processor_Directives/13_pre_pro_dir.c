#include<stdio.h>
#include<stdlib.h>

#define SUM(a, b) (a + b)

int main()
{
	system("clear");

	printf("Sum is %d\n",SUM(3 , 2));
	printf("Sum is %d\n",SUM(3 + 2, 3 - 2));

	return 0;
}

