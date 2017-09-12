#include<stdio.h>

void my_puts(char *str)
{
	int i=0;
	while(str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}

	putchar('\n');	

}

int main()
{
	char str[10]="hello";

	my_puts(str);
	my_puts("raj\fhi\tkumar\nmishra");

	return 0;
}
