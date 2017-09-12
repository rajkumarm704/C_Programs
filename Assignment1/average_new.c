#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	system("clear");

	int idx;
	float sum = 0;
	
	for ( idx = 1; argv[idx] != NULL; idx++ )
		sum += atoi(argv[idx]);

	printf("average: %f\n",sum/(idx-1) );

	return 0;
}
