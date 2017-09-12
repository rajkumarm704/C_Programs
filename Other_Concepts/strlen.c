#include<stdio.h>
#include<string.h>

int main()
{
	int len;;
	char name[5]="raj";

	len=strlen(name);

	printf("The length of '%s' is: %d\n",name,len);

	return 0;
}
