#include<stdio.h>
int main()
{

char i;
char ch;

while(1)
{

	for(i=0;i<=127;i++)
	{
		//Print only the ASCII range
		if(i>29 || i<40 || i>64 || i<91 || i>96 || i<123)
			printf("%c, ",i);
	}

		//Ask user for options
		printf("\nDo you want to continue(Y/N):");
		ch=getchar();
		while(getchar() != '\n');
		if(!(ch == 'Y' || ch == 'y'))
		{
			break;
		}
}
return 0;
}

