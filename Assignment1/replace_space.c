#include<stdio.h>
int main()
{
int count=0,i=0,flag=1;
char c[50],ch;

printf("Enter some characters:");
	
while(1)
{
	ch=getchar();
	if(ch==' ' && flag==1 || ch=='\t' && flag==1)
	{
		c[i]=' ';
		flag=0;
		i++;
	}		
	if(ch>32)
	{
		c[i]=ch;
		flag=1;
		i++;
	}

	

//	printf("Count:%d,\ti:%d\n",count,i);

	if(ch==EOF)
		break;
}

	count=i;
	printf("\n");

	for(i=0;i<count;i++)
	{
		if(c[i]==' ' && i==0 || c[i]=='\t' && i==0)
			continue;
	
		printf("%c",c[i]);
	}
	printf("\n");

return 0;

}
