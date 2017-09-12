#include<stdio.h>
#include<stdlib.h>

struct Nibble
{

	unsigned char lower : 4;
	unsigned char upper : 4;

//	unsigned int lower : 4;
//	unsigned int upper : 4;

};

int main()
{

	system("clear");

	struct Nibble n;
	n.lower = 1;
	n.upper = 2;

	printf("Size of Nibble: %ld\n", sizeof(struct Nibble) );
	printf("Value at n: %#x\n", *( (char *)(&n) ) );
//	printf("Size of n.lower: %d\n", sizeof(n.lower) );
//	printf("Size of n.upper: %d\n", sizeof(n.upper) );
	return 0;
}
