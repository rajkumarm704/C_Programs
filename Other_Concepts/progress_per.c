#include<stdio.h>
int main()
{
int count=0;

while(count!=50)
{
	printf("->",count);
	fflush(stdout);
	count++;
	usleep(100000);
	printf("\b",count);
}
	printf("->",count);
	printf("\nWork Completed...\n");
return 0;
}

/*

while(count!=101)
{
	printf("%d%%\r",count);
	fflush(stdout);
	count++;
	usleep(100000);
}
*/
