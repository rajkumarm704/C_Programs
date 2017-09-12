#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int main()
{
	system("clear");

	printf("Before MAX:%d\n",MAX);

#undef MAX
#define MAX 40

	printf("After MAX:%d\n",MAX);
	return 0;
}
