#include<stdio.h>

int strlen_func(char *str1, char *str2)
{
	int i=0,count1=0,count2=0;

	while(str1[i] != '\0')
	{
		count1++;
		i++;
	}

	i=0;
	while(str2[i] != '\0')
	{
		count2++;
		i++;
	}

	if(count1==count2)
		return 1;
	else
		return 0;
}

int strcasecmp_func(char *str1, char *str2, int *value)
{
	int val1,val2,i=0,count,result=0;

	while(str1[i] != '\0')
	{
		if(str1[i]==str2[i])
		{
			i++;		
			continue;
		}
		else
		{
			return str2[i] - str1[i];
		}
	}

	return 0;
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
 
	count=strlen_func(str1,str2);

	if(count==1)
		result=strcasecmp_func(str1,str2,&value);
	else if(count==0)
		result=0;

	if(result==0)
		printf("Strings matched.\n");
	else 
		printf("Strings not matched. The difference is %d\n",result);

end:	return 0;
}
