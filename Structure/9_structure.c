#include<stdio.h>
#include<stdlib.h>

//Anonymous Structure
struct 	
{
	char c;
	int n;
}s1,s2;	//Global variables

int main()
{

	system("clear");

	s1.n = 7;
	s1.c = 'A';
	printf("s1.n: %d s1.c: %c\n", s1.n, s1.c);

	s2.n = 71;
	s2.c = 'Z';
	printf("s2.n: %d s2.c: %c\n", s2.n, s2.c);

	return 0;
}
