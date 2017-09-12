#include<stdio.h>
#include<string.h>

void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc strtok_string_replace.c -o strtok_string_replace.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}

void main()
{
	cne();
	ubound();
	
	char str1[100], str2[100], str3[100];
	char *ptr, temp[100] = "";

	printf("Enter the first string:");
	scanf("%[a-z A-Z]",str1);
	
	while(getchar() != '\n');

	printf("Enter the string to replace:");
	scanf("%[a-z A-Z]",str2);

	while(getchar() != '\n');

	printf("Enter the new string:");
	scanf("%[a-z A-Z]",str3);

	while(getchar() != '\n');

	ptr = strtok(str1,str2);

	while( ptr != '\0' )
	{		
		strcat(temp,ptr);
		strcat(temp, str3);
		ptr = strtok(NULL,str2);
	}

	printf("\n%s\n",temp);

	lbound();
}
