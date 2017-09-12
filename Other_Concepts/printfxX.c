#include<stdio.h>
int main()
{

char c,ch;

while(1)
{
	printf("Enter a character:");
	c=getchar();
	while(getchar() != '\n');

/*	printf("x:%x\n",0xABC);
	printf("X:%X\n",0XabcDE);
	printf("e:%e\n",2.356);
	printf("3d:%3d|%3d\n",10,10);
	printf("s:%6s\n","hello");
	printf("*d:%*d\n",5,2);
	printf("*s:%*s\n",4,"raj");

	printf("*d,*d:|%*d|%*d\n",5,2,5,2);
*///	printf("3.1d:%3.1d|%3.3d\n\n",10,10);

	int i;

//	printf("    %*d\n",-2,1);

/*	for(i=1;i<10;i++)
	{
		if(i==5)
		printf("%*c\t\tcount:%d,%d\n",5,c,5,5);		
		else if(i>5)
		printf("%*c%*c\t\tcount:%d,%d\n",10-i,c,2*i-10,c,10-i,2*i-10);
		else if(i<5)
		printf("%*c%*c\t\tcount:%d,%d\n",i,c,10-2*i,c,i,10-2*i);
	}
*/

	for(i=1;i<10;i++)
	{
		if(i==5)
		printf("%*c\n",5,c);		
		else if(i>5)
		printf("%*c%*c\n",10-i,c,2*i-10,c);
		else if(i<5)
		printf("%*c%*c\n",i,c,10-2*i,c);
	}


	//Ask user for options
	printf("\nDo you want to quit(Y/N):");
	ch=getchar();
	while(getchar() != '\n');
	if((ch == 'Y' || ch == 'y'))
	{
		break;
	}

}
	return 0;
}
