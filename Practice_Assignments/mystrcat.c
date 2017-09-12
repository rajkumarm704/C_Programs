#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

char * mystrcat(char *str1, char *str2)
{

//	return ( ( *(str2++) != '\0' ) ? ( *( str1 + sizeof(str1)++ ) = *(str2) ): str1 );

/*	printf("str1:");
	while ( *(str1++) != '\0' )
		printf("%c", *(str1) );

	printf("\n\nstr2:");
*/
		printf("\nsizeof( str1 ):%d\n", sizeof(str1));
	while ( *(str2++) != '\0' )
	{
		*( str1 + sizeof(str1)++ ) = *(str2);
		printf("\nsizeof( str1 ):%d\n", (sizeof(str1)));
//		printf("%c", *( str1 + sizeof(str1)  ) );		
		printf("%c", *(str1) );		
	}

	str1  = str1 - sizeof(str1) ;
	printf("str1:%s", str1 );		

//		printf("%c", *(str2) );
	printf("\n");

	return str1;

}

int main()
{

	system("clear");

	char str1[100], str2[100];

	printf("Enter first string:"), scanf("%[^\n]", str1);
	__fpurge(stdin);
	printf("Enter second string:"), scanf("%[^\n]", str2);
	__fpurge(stdin);

	printf("Final string is %s\n",mystrcat(str1, str2) );

	return 0;
}
