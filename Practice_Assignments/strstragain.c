#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

char * strstragain(const char *str1, const char *str2)
{
	int i, j, count = 0;
	int str2_len = strlen(str2);

	for( i = 0, j = 0; str1[i] != '\0'; i++)
	{
		if( str1[i] == str2[j] )
			j++;
		else if( j == str2_len )
			break;
	}

	return (char *)str1 + i - count - 1;
}
int main()
{

	system("clear");
	char str1[50], str2[50], *result;
	printf("Enter first string:"),scanf("%[^\n]", str1);
	__fpurge(stdin);
	printf("Enter second string:"),scanf("%[^\n]", str2);
	__fpurge(stdin);
	result = strstragain(str1, str2);
	printf("String is %s\n", result);

	return 0;

}
