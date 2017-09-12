#include<stdio.h>
#include<stdlib.h>

#define SUM(a, b) (a + b)

int main()
{
	system("clear");

	int a = 3, b = 2, r1;
	float f1 = 2.6, f2 = 5.2, r2;

	r1 = SUM(a , b);
	r2 = SUM(f1, f2);

	printf("INT Sum is %d\n",r1);
	printf("FLOAT Sum is %.2f\n",r2);

	return 0;
}

