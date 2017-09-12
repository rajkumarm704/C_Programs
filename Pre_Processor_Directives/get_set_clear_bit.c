#include<stdio.h>
#include<stdlib.h>

#define GET_BIT(num, bit) (num &= 1 << bit, num = num >> bit)
#define SET_BIT(num, bit) (num |= 1 << bit)
#define CLEAR_BIT(num, bit) ( num & (~(1 << bit) ) )

int main()
{
	system("clear");

	int a = 0xff, b = 0x80;
	
	printf("a & ( ~(1<<2) ): %x\n",a & (~(1<<2)) );
	printf("Bit is %x\n",GET_BIT(a,2) );
	printf("Set Bit result %x\n",SET_BIT(b,2) );

	a = 0xff;
	printf("Clear Bit result: %x\n",CLEAR_BIT(a,2) );

	return 0;
}

