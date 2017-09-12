#include<stdio.h>
void main()
{
	char str[] = "Hello";
	char *str2 = "Hello";
	str[0] = 'W';
	printf("String:%s",str);
	*str2 = 'W';
	printf("String:%s",str2);
}
