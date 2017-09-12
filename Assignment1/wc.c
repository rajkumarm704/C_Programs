#include<stdio.h>
int main()
{
int count=0,wc=0,lc=0,flag=0;
char c;

printf("Enter some characters:");

while(1)
{
	c=getchar();
	count++;
	if(c==' ' && flag==0)
	{
		flag=2;
		continue;
	}
	if(c==10)
	{
		lc++;
		flag=1;
		continue;
	}
	if(c>32 && flag==1)
	{
		wc++;
		flag=0;
	}
	if(c>32 && flag==2)
	{
		wc++;
		flag=0;
	}

/*	if(c==' ' && flag==2 || c=='\n' && flag==2)
	{
//		wc++;
		flag=0;
	}
*/
	if(c==EOF)
		break;
}

printf("\nThe result is\n l:%d\tw:%d\tc:%d\n",lc,wc+1,count-1);
return 0;
}
