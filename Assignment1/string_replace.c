#include<stdio.h>
#include<string.h>

int flag = 0;

void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc string_replace.c -o string_replace.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}


char *string_replace(char *str1, char *str2, char *str3)
{
	int i = 0,j = 0,count = 0, count_t = 0;
	static char* b_add;
	count = strlen(str2);
	static char temp[100] = "";
	char ch[1];
	static int func_call_count = 0;


	printf("Func call count:%d\n",func_call_count);
	if(func_call_count >= 10)
		return 0;


	while( str1[i] != '\0')
	{
		if(str1[i] == str2[j])
		{
			j++;
		}
		else if( j == count)
		{
			count_t = i - j;
			b_add = str1 + i - j;
			break;
		}
		else
			j = 0;

//		printf("str1[%d]:%c, str2[%d]:%c\n",i,str1[i],j,str2[j]);
		i++;
	
	}


	for( j = count_t ; j < i; j++)
	{
//		printf("11\n");
//		printf("str1[%d]:%c\t",j,str1[j]);
		str1[j] = '\5';
//		printf("str1[%d]:%c\n",j,str1[j]);
	}
	
	//taking strings prior to string 2
	for ( j = 0; j < i - count + func_call_count; j++)
	{
//		printf("j:%d, i - count:%d,str1[%d]:%c\n",j,i - count,j,str1[j]);
		ch[0] = str1[j];
		strcat(temp,ch);
	}
	
	temp[ j + 1 ] = '\0';

	strcat(temp,str3);


	printf("\t\tTemp string:%s\n",temp);

	if(strlen(temp) == strlen(str1))
	{
		count = strlen(temp);
//		printf("Temp Count:%d\n",count);
		temp[ count ] = '\0';
		flag = 1;
		return temp;
	}

	//Taking strings after string 2
	for( i = count_t; str1[i] != '\0'; i++)
	{
//		printf("i:%d, count_t:%d,str1[%d]:%c\n",i,count_t,i,str1[i]);
		ch[0] = str1[i];
		strcat(temp,ch);
	}
	

	func_call_count++;

	return temp;

}

void reduce_string(char *str)
{
	int i = 0, j = 0;

	printf("\n\nOriginal string:");
	
	str[ strlen(str) + 1 ] = '\0';

//	while( str[i] != '\0')
		printf("%c",str[i]);

	printf("\n");

	while( str[i] != '\0' )
	{
		if( str[i] == '\5' )
		{
			for( j = i; j < 8; j++)
				str[ j ] = str[ j + 1 ];
		

		}

		i++;
	}

	printf("Reduced string: %s\n\n",str);

}

void main()
{
	cne();
	ubound();

	char str1[100], str2[100], str3[100];
	char *ptr;

	printf("Enter the first string:");
	scanf("%[a-z A-Z]",str1);
	
	while(getchar() != '\n');

	printf("Enter the string to replace:");
	scanf("%[a-z A-Z]",str2);

	while(getchar() != '\n');

	printf("Enter the new string:");
	scanf("%[a-z A-Z]",str3);

	while(getchar() != '\n');

	ptr = string_replace(str1,str2,str3);
//	printf("11\n");
//	reduce_string(ptr);

//	while( *ptr != '\0' )
//	{
		printf("The final string :%s\n",ptr);

//		reduce_string(ptr);
//		ptr = string_replace(ptr,str2,str3);

//	}

	lbound();
}
