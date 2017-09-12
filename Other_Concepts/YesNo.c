#include<stdio.h>
int main()
{
	char ch;
	int i=0;
	while(1)
	{
		printf("\nLooped %d times.\n",i);
		printf("Do you want to continue(Y/N):");
		ch=getchar();
		while(getchar() != '\n');
		if(!(ch=='Y' || ch=='y'))
		{
			break;
		}
		i++;
	}
return 0;

}
