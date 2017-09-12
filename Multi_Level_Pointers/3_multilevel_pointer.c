#include<stdio.h>
int main()
{
	int x = 10;
	int *ptr1;
//	int ** const ptr2;
//	int * const *ptr2;
	int const **ptr2;

	ptr2 = &ptr1;
	*ptr2 = &x;
	**ptr2 = 20;

	return 0;
}
