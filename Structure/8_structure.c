#include<stdio.h>
#include<stdlib.h>

struct Number
{
	char x : 3;
//	unsigned char x : 3;
}n;

int main()
{

	system("clear");

//	struct Number n;
	n.x = 7;
	printf("n.x:%d\n", n.x);
	n.x = 3;
	printf("n.x:%d\n", n.x);

	return 0;
}
