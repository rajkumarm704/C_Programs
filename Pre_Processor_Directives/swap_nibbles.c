#include<stdio.h>
#include<stdlib.h>

#define SWAP_NIBBLES(num) ( (num & 0xf << 4) >> 4 | (num & 0xf) << 4 )  

int main()
{
	system("clear");

	int a = 0x8f;
	
	printf("Set Bit result %x\n",SWAP_NIBBLES(a) );


	return 0;
}

