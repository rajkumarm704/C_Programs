#include<stdio.h>
#include<stdlib.h>

#define CASE 2

struct Nibble
{
	unsigned char lower : 4;
	unsigned char upper : 4;
};

int main()
{
	system("clear");

#if CASE == 2
	printf("CASE II\n");
	struct Nibble *n;
	char ch, t;

	n = (struct Nibble *)&ch;

	printf("Enter a Byte:"), scanf("%hhx", &ch);

	printf("Original Value : %#hhx\n", ch );
	printf("upper nibble: %#x, lower nibble: %#x \n\n", n->upper, n->lower );

	t = n->lower;
	n->lower = n->upper;
	n->upper = t;

	printf("Swapped Value: %#hhx\n", ch );
	printf("upper nibble: %#x, lower nibble: %#x \n\n", n->upper, n->lower );

#elif CASE == 1
	printf("CASE I\n");
	struct Nibble n, t;

	printf("Enter a Byte:"), scanf("%hhxx", (char *)&n);
	printf("Original Value : %#hhx\n", *( (char *)(&n) ) );
	printf("upper nibble: %#x, lower nibble: %#x \n\n", n.upper, n.lower );

	t.lower = n.lower;
	n.lower = n.upper;
	n.upper = t.lower;

	printf("Swapped Value: %#hhx\n", *( (char *)(&n) ) );
	printf("upper nibble: %#x, lower nibble: %#x \n\n", n.upper, n.lower );
#endif



	return 0;
}
