#include<stdio.h>
#include<stdlib.h>

#define SQUARE(x) x * x
//#define square(x) x * x


int square(int x)
{
	return x * x;
}

int main()
{
	system("clear");

	printf("Suare of 2:%d\n",square(2));
	printf("Suare of 3:%d\n",SQUARE(3));
//	printf("Suare of 3:%d\n",square(3));
	return 0;
}

