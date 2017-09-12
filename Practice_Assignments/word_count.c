#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

	int i, word_count = 0, flag = 0;
	char buffer[1024];

	printf("Enter string:"),scanf("%[^EOF]", buffer);

	for( i = 0; buffer[i] != '\0'; i++ )
	{
		if( buffer[i] >= 65 && buffer[i] <= 90 || buffer[i] >= 97 && buffer[i] <= 122 && (buffer[i + 1] == ' ' || buffer[i + 1] == '\n' || buffer[i + 1] == '\t' || buffer[i + 1] == '\0' ) )
		{
			word_count++;
		}

	}//for

	printf("\nWord count:%d\n", word_count);

	return 0;
}
