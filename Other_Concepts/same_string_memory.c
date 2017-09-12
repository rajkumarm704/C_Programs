#include<stdio.h>
void main()
{
	char *str1 = "Hello", *str2 = "Hello";
	if(str1 == str2)
		printf("Same String Address\n");
	else
		printf("Different strinf address\n");
}
