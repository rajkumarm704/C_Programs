#include<stdio.h>

int main()
{
	short x;
	int y;
	long z;
	
	printf("%u,%d,%u\n",sizeof x, sizeof y, sizeof z);
	printf("%d %u %u %u\n",sizeof(int),sizeof(long),sizeof(short),sizeof(long long));
	return 0;
} 
