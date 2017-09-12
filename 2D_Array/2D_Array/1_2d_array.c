#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");

	int i, j, rows = 2, cols = 3;
	int a[2][3] = { {1,2,3}, {4,5,6} };

	printf("\n");
	printf("a + 0\t\t: %p\n", a + 0);
	printf("a + 1\t\t: %p\n", a + 1);
	printf("\n");
	printf("&a + 0\t\t: %p\n", &a + 0);
	printf("&a + 1\t\t: %p\n", &a + 1);
	printf("\n");
	printf("*a\t\t: %p \n", *a);
	printf("&*a\t\t: %p \n", &*a);
	printf("*&a\t\t: %p \n", *&a);
	printf("*(a + 0)\t: %p \n", *(a + 0));
	printf("*(a + 1)\t: %p \n", *(a + 1));
	printf("**(a + 0)\t: %d \n", **(a + 0));
	printf("**(a + 1)\t: %d \n", **(a + 1));

	return 0;
}
