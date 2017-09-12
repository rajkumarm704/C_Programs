#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

void mean( int count, ... )
{
	int i;
	double mean = 0;
	va_list va;
	va_start(va, count);
	for( i = 0; i < count; i++ )
		mean += va_arg(va, double);

	mean /= count;
	printf("Mean is:%lf\n", mean);

	va_end(va);

}

int main()
{

	system("clear");

	mean(5, 1.2, 3.2, 4.5, 5.4, 6.7 );

	return 0;
}
