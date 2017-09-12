/**********

const int *p OR int const *p
	here *p value cannot be modified

int * const p
	here p value cannot be modified

*********/


#include<stdio.h>
int main()
{
	int x = 10;
//	const int *i;
// 	int const *i;
	const int const *p;
//	int * const i = &x;
//	i = &x;
//	*i = 11;
	x = 11;
	printf("i:%d, Address of i:%p\n", *i, i);
	return 0;
}
