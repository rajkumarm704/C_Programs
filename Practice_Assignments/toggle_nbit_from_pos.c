#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

	int num, pos, n;
	int mask, bit;

	printf("Enter number, position and n:"),scanf("%x %d %d", &num, &pos, &n);

	mask = (1 << n) - 1;

	mask = ( mask << pos ) - 1;

	num = num ^ mask;

	printf("Toggled number: %x\n", num);

	return 0;
}
