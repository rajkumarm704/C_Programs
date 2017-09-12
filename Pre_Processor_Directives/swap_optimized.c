#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");
	
	int a = 10, b = 20;

	printf("a:%d, b:%d\n",a, b);

	#ifdef OPTIMISED
		a = a ^ b;
		printf("a:%d, b:%d\n",a, b);
		b = a ^ b;
		printf("a:%d, b:%d\n",a, b);
		a = a ^ b;
		printf("a:%d, b:%d\n",a, b);
	#else
		int temp;
		temp = a;
		a = b;
		b = temp;
		printf("a:%d, b:%d\n",a, b);
	#endif

	return 0;
}

