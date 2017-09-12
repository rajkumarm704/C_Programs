#include<stdio.h>
#include<string.h>

int main()
{
	int len=0;
	char name[3]="raj",a[3]="hi";
	printf("Address:name:%p,a:%p,len:%p\n",name,a,&len);
	len=strlen(name);

	printf("The length of '%s' is: %d\n",name,len);

	return 0;
}
