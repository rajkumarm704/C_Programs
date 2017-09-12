#include<stdio.h>
#include<stdlib.h>
typedef int array_of_100[100];


int main()
{

	system("clear");

	array_of_100 array;

	array[0] = 1524;

	printf("size of array: %d\n", sizeof(array) );
	printf("array[0] : %d\n", array[0] );

	return 0;
}
