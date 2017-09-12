#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");
	
	int a = 5, b = 3;

	printf("a:%d, b:%d\n",a, b);

	a = a ^ b;
	printf("a^b, a:%d\n",a);
	b = a ^ b;
	printf("a^b, b:%d\n",b);
	a = a ^ b;
	printf("a^b, a:%d\n",a);

	return 0;
}

