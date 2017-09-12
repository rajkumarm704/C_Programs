#include<stdio.h>
#include<stdlib.h>

//Anonymous Structure
struct 	
{
	char c;
	int n;
}s1 = { .n = 20, .c = 'g', .c = 'E' }, s2 = { .c = 'S' };	//Global variables

int main()
{

	system("clear");

	printf("s1.n: %d\n", s1.n);
	printf("s1.c: %c\n", s1.c);
	printf("s2.c: %c\n", s2.c);
	return 0;
}
