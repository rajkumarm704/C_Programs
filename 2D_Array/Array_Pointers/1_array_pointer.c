#include<stdio.h>

int main()
{
	int i;
	int *ptr[3];
	int a = 1, b = 2, c = 3;
	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;

	for( i = 0; i < 3; i++ )
		printf("%d ", *ptr[i]);

	printf("\n");

	return 0;
}
