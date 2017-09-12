#include<stdio.h>
#include<stdlib.h>
void f1(void);
void f2(void);

#define MAX 100

int main()
{
	system("clear");

	printf("MAX:%d\n",MAX);
	f1();
	printf("MAX:%d\n",MAX);
	f2();
	printf("MAX:%d\n",MAX);

	return 0;
}

void f1(void)
{
#undef MAX
#define MAX 200
}

void f2(void)
{
#undef MAX
#define MAX 300
}
