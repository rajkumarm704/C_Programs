#include<stdio.h>

int main()
{
	char str[10]="hello";
	int i=0;
	char *ptr,*ptr2;

	ptr=str;
	ptr2=str;

	while(*ptr != '\0')
	{
		putchar(*ptr);
		ptr++;
	}

	putchar('\n');	

	while(ptr2[i] != '\0')
	{
		putchar(ptr2[i]);
		i++;
	}

	putchar('\n');	

	printf("Address\nstr:%p\nptr:%p\nptr2:%p\n",str,ptr,ptr2);

	return 0;
}
