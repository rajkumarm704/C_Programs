#include<stdio.h>				//Date:30th June, 2017
#include<stdlib.h>
#include "one.h"

#define ARRAY_SIZE 10
#define PI 3.14
#define ERRMSG "Error! Problem in your code!!"

int main()
{
	system("clear");

	int arr[ARRAY_SIZE];
	int r = 5;

//	printf("num = %d\n", num);
	printf("average = %f\n", average(2, 3));
	printf("sum = %d\n", add(4, 5));
	printf("%s\n", ERRMSG);

	printf("Area = %lf\n", PI * r * r);

#if 0
	/* dead code */
	printf("Hello\n");
#endif

	return 0;
}
