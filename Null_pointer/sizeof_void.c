#include<stdio.h>
int main()
{
/*	printf("sizeof void:%u\n",sizeof(void));*/
//	printf("sizeof void pointer:%u\n",sizeof(void *));

	short *sptr;
	int x = 0x12345678;
	void *vptr;
	vptr = &x;
	
	char *ptr;

	printf("Original Value:%x\n",x );
	
//	sptr = ((char *)vptr+1);
//	vptr = *((char *)vptr+1);

	ptr = ((char *)vptr+1);

	printf("ptr:%p\n", ptr );
	printf("*ptr:%x\n", *ptr );
//	printf("Value:%x\n", *((char *)vptr+1) );
//	printf("Value:%x\n", *sptr );
	printf("Address of vptr:%p\n",&vptr);
	return 0;
}
