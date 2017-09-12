/* HASH HASH OPERATOR */

#include<stdio.h>
#include<stdlib.h>

#define CAT1(x, y) (x##y)
#define CAT2(x, y) (x##_##y)

int main()
{
	system("clear");

	int int_val = 4;
	float float_val = 2.54;
	int bird_count = 20;

	printf("int val : %d\n", CAT1(int, _val));
	printf("flaot val : %f\n", CAT2(float, val));
	printf("bird count : %d\n", CAT2(bird, count));

	return 0;
}

