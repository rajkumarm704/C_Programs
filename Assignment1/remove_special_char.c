#include<stdio.h>
int main()
{
int i=0,j;
char ch,str[20];
printf("Enter a string:");
ch=getchar();
while(ch!=EOF)
{
	if(ch>32 && ch <48 || ch>57 && ch < 65 || ch>90 && ch<97 || ch>122 && ch<127)
		i--;
	else
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
	
