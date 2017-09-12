#include<stdio.h>
#include<unistd.h>
#include"template1"
#include"increment.h"
#include"average.h"

int num1 = 2, num2 = 3;
//extern float average(int x, int y);
//extern void increment(void);
int count = 0;
int main()
{
	cne();
	ubound();

	float avg;

	while(1)
	{
//		printf("Hello\n");
		avg = average(num1, num2);
		printf("Sum: %d, Average: %f\n", num1+num2, avg);
		increment();
		sleep(1);
		count++;

if(count == 5)
	break;

	}

	lbound();

	return 0;
}
