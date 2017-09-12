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
			if(str1[i]>=65 && str1[i] <= 90)
			{
				val1=90-(int)str1[i];
			}
			else if(str1[i]>=97 && str1[i] <= 122)
			{
				val1=122-(int)str1[i];
			}


			if(str2[i]>=65 && str2[i] <= 90)
			{
				val2=90-(int)str2[i];
			}
			else if(str2[i]>=97 && str2[i] <= 122)
			{
				val2=122-(int)str2[i];
			}

			if(val1==val2)
			{
				val1=0;
				val2=0;
				i++;
				continue;
			}
			else
			{
				*value=val2-val1;
				return 0;
			}

		}
	}

	return 1;			
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
	{
		printf("Strings not matched.\n");
		goto end;
	}

	if(result==1)
		printf("Strings matched.\n");
	else if(result==0)
	{
		printf("Strings not matched.\n");
		printf("The difference between ASCII values is %d.\n",value);
	}

end:	return 0;
}
