#include<stdio.h>
int main()
{
	int x=0x12345678;
	int *iptr;
	char *cptr;
//	x=0x12345678;
	iptr=&x;
	cptr=&x;
	printf("*cptr:%x\n",*cptr);
	printf("*iptr:%x\n",*iptr);

	return 0;
}
