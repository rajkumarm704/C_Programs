#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>

char *add;

char * my_strtok( char *str1, const char *str2)
{
	int i, j;
	static char *sptr;
	static char *tsptr;

	sptr = tsptr;

	while( 1 )
	{
		for( i = 0; ; i++ )
		{
			if( str1 != NULL )
			{
				for( j = 0; str2[j] != '\0'; j++ )
				{
					if( str1[i] == str2[j] )
					{
						str1[i] = '\0';
						sptr = str1 + i + 1;
						tsptr = sptr;
						return str1;
					}
				}//for
			}//if
			else if(sptr[0] == '\0')
				return NULL;
			else if( str1 == NULL )
			{
				for( j = 0; str2[j] != '\0'; j++ )
				{
					if( sptr[i] == str2[j] )
					{
						sptr[i] = '\0';
						tsptr = sptr + i + 1;
						return sptr;
					}
					else if( sptr[i] == '\0' )
					{
						tsptr = sptr + i;
						return sptr;
					}
				}//for
			}//else if
		}//for
	}//while
}//function

int main()
{

	system("clear");

	char str1[50], str2[50], *ptr;

	printf("Enter the first string:"), scanf("%[^\n]", str1);
	__fpurge(stdin);
	printf("Enter the second string:"), scanf("%[^\n]", str2);
	__fpurge(stdin);

	ptr = my_strtok( str1, str2);

	while( ptr != NULL )
	{
		printf("%s\n", ptr);
		ptr = my_strtok(NULL, str2);
	}

	return 0;
}
