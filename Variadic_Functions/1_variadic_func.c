#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>
#include<stdarg.h>

float average(int count, ... )
{
	va_list ap;
	int i, sum = 0;
	va_start(ap, count);
	
	for(i = 0; i < count; i++ )
		sum += va_arg(ap, int);

	va_end(ap);

	return (float)sum/count;
}


int main()
{
	system("clear");

	float avg;

	printf("Average is %.2f\n",average(5, 10, 22,  3.5, 21, 7.2) );
	return 0;
}
