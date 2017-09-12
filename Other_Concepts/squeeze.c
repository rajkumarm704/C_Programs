#include<stdio.h>

int strlen_func(char *str)
{
	int i=0,count=0;

	while(str[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}


void squeeze_func(char *str1, char *str2,int count)
{
	int i=0,j=0;

	while(str1[i] != '\0')
	{
		while(str2[j] != '\0')
		{
			if(str1[i]==str2[j])
			{
				str1[i]='\5';
				j++;
			}
			else
			{
				j++;
				continue;
			}
		}
		j=0;
		i++;
	}
}

int main()
{
	char str1[20],str2[20];
	int count,result,value=0;

	printf("Enter first string:");
	scanf("%[a-z A-Z]",str1);

	while(getchar() != '\n');

	printf("Enter second string:");
	scanf("%[a-z A-Z]",str2);

	count=strlen_func(str1);
	printf("Count:%d\n",count);
	squeeze_func(str1,str2,count);

	printf("The squeezed string is %s\n",str1);

	return 0;
}
