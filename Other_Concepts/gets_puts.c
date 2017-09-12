#include<stdio.h>
#include<ctype.h>
int main()
{
	char str[20];
	puts("Enter a string.");
	fgets(str,10,stdin);
	puts(str);
	return 0;
}
