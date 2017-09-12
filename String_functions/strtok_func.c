#include<stdio.h>

char *base_address, *b_add;
int ba_count = 0, str_len=0;

//Function to calculate length of string
int strlen_func(char *str)
{
	int i;

	for(i = 0; str[i] != '\0'; i++);

	return i;
}


char* strtok_func(char *str, char *delimiter)
{
//i:string index
//j:delimiter index
//ii:string index in case of delimiter and string mis-match
//jj:delimiter index in case of delimiter and string mis-match

	int i=0,j=0,ii,jj;

	ba_count = 0;
	b_add=str;

	if(str == NULL)
	{
//		printf("NULL, base_address:%p\n",base_address);
		str=base_address;
		b_add=base_address;
	}

	while(str[i] != '\0')
	{
//		printf("\t\ttchar:%c, i:%d\n",tchar,i);
/*
		printf("str[%d]:%c\t",i,str[i]);
		printf("delimiter[%d]:%c\t",j,delimiter[j]);
		printf("i:%d, j:%d\t",i,j);

		printf("address:%p, ba_count:%d\t",&str[i],ba_count);
		printf("base address:%p\n",base_address+ba_count);
*/
		if(delimiter[j]=='\0')
		{
			j=0;
			base_address = str+ba_count;
/*			printf("\naddress:%p, ba_count:%d\t",&str[i],ba_count);
			printf("base address:%p\t",base_address+ba_count);
			printf("b_add:%p\n",b_add);
*/			return b_add;
		}

		if( str[i] == delimiter[j] )
		{
			str[i]='\0', i++, j++, ba_count++, str_len--;
			continue;
		}
		else if( str[i] != delimiter[j] && j > 0 )
		{
/*			printf("else\n");

			printf("i:%d, j:%d\t",i,j);
			printf("address:%p, ba_count:%d\t",&str[i],ba_count);
			printf("base address:%p\n\n",base_address+ba_count);
*/
			ii=ba_count-j;

			for(jj=0;jj<j;ii++,jj++)
			{
				str[ii]=delimiter[jj];
//				printf("str[%d]:%c\t",ii,str[ii]);
			}
			base_address = str + ++str_len;
			return b_add;
			break;
		}


		i++;
		ba_count++;
	}
	if(str[i] == '\0')
	{
		base_address = str+ba_count;
		return b_add;
	}
}

//strstr function
char* strstr_func(char *str, char *str2)
{
	int i = 0,j = 0,count;
	count = strlen_func(str2);

	while(str[i] != '\0')
	{
		if(str2[j] == '\0' && j == count)
		{
//return the base address of string with current string index subtracting the length of second string. This returns the base address of first occurence of character of string 2 present in string one
			return str + i - j;
		}

//Compare the string one with string two and continue till all characters of second string is matched in first string.
		if( str[i] == str2[j] )
		{
			j++;
		}
		else
		{
			j = 0;			
		}
		i++;
	}

	if( i == strlen_func(str)  )
		return str + i;
}



int main()
{
	char str[100],delimiter[20],*ptr,str2[100];
	int count,result,value=0,i=0,option;
	
	printf("Choose a function:\n1. strtok\n2. strstr\nYour option:");
	scanf("%d",&option);
	
	while(getchar() != '\n');

//Perform strtok operation
	if(option == 1)
	{
		printf("Enter the string:");
		scanf("%s",str);

		printf("Enter the delimiter:");
		scanf("%s",delimiter);

		str_len = strlen_func(str);
		ptr = strtok_func(str,delimiter);

		while(*ptr != '\0')
		{
			printf("%s\n",ptr);
			ptr = strtok_func(NULL,delimiter);
		}
	}

//Perform strstr operation
	else if(option == 2)
	{
		printf("Enter the first string:");
		scanf("%[a-z A-Z]",str);

		while(getchar() != '\n');

		printf("Enter the second string:");
		scanf("%[a-z A-Z]",str2);
		
		ptr = strstr_func(str,str2);

		if(*ptr == '\0')
			printf("Null\n");
		else
			printf("%s\n",ptr);

	}


	return 0;
}





