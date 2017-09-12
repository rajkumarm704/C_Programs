#include<stdio.h>
int main()
{
	printf("1. Hello World\n");
	printf("2. Hello\tWorld\n");
	printf("3. Hello\vWorld\n");
	printf("4. Hello World\f");
	printf("5. Hello World\r");
	putchar('A');
	putchar('\n');
	printf("6. Hello\b World\n");
	printf("7. \"Hello World\"");
	putchar('\n');
	printf("8. A\\B\\C\n");
	printf("9. Hello World\r");
//	putchar('\n');
return 0;
}
