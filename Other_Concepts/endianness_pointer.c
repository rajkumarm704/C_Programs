
#include<stdio.h>
int main()
{
	int x=0x12345678;
	char *cptr;
//	char c_l,c_b;
	
	cptr=&x;
	
//	c_b=x>>24;
//	c_l=x;
	
	if(*cptr==0x78)
		printf("Little endian.\n");
	else if (*cptr == 0x12)
		printf("Big endian.\n");

	return 0;
}
