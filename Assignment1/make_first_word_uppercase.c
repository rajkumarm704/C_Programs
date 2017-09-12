#include<stdio.h>
int main()
{
int i=0,j,temp,flag=0;
char ch,str[100];

printf("Enter a string:");
ch=getchar();

while(ch!=EOF)
{
	if(i==0) 
	{
		temp=ch-97;
		temp+=65;
		str[i]=temp;
	}

	if(ch==' ' &&flag==0)
		flag=1;		
	if(ch>=97 && ch <=122 && flag==1)
	{
		temp=ch-97;
		temp+=65;
		str[i]=temp;
		flag=0;
	}
	else if(i!=0)
		str[i]=ch;

	i++;
	ch=getchar();

}

putchar('\n');

for(j=0;j<i;j++)
	putchar(str[j]);

putchar('\n');

return 0;
}
	
