#include<stdio.h>

char* strrev_func(char *str, char *str_rev, int i, int count)
{	
	count--;
	if(count >= 0)
	{
		str_rev[count]=str[i];
		i++;
		strrev_func(str,str_rev,i,count);
	}
	else
	{
		str_rev[i] = '\0';
		return str_rev;
	}
}

char* iterative_reverse(char *str,char *str_rev, int count)
{
	int i;

	i=0;
	count--;

	while(str[i] != '\0')
	{
		str_rev[count]=str[i];
		count--;
		i++;
	}

	str_rev[i] = '\0';
	return str_rev;
}

int main()
{
	char str[100],str_rev[100],*str_ptr;
	int i,count=0,option;

	printf("Enter a string:");
	scanf("%s",str);

	printf("Enter the method:\n1. Recurrsion\n2. Iterative\nChoose an option:");
	scanf("%d",&option);

	i=0;
	while(str[i] != '\0')
	{
		count++;
		i++;
	}

	if(option==1)
	{
		str_ptr=strrev_func(str,str_rev,0,count);
		printf("Reverse string is:%s\n",str_ptr);
	}
	else if(option==2)
	{
		str_ptr=iterative_reverse(str,str_rev,count);
		printf("Reverse string is:%s\n",str_ptr);		
	}
	
	return 0;
}
