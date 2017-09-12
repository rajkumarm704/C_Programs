#include<stdio.h>
int main()
{
	char ch;
	ch=getchar();
	while(ch != EOF)
	{
		putchar(ch+1);
		ch=getchar();
	}
	puts("DONE");
	return 0;
}
