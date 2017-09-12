#include<stdio.h>
#include<string.h>

int main()
{
	int len, i, j, count = 0;
	char str1[100], str2[100];

	printf("Enter first string:");
	scanf("%[a-z A-Z]",str1);
	
	while(getchar() != '\n');

	printf("Enter second string:");
	scanf("%[a-z A-Z]",str2);

	while(getchar() != '\n');
	
	len = strlen(str1);

	for( i = 0; i < len; i++ )
	{
		for( j = 0; j < len; j++)
		{
//			printf("str1[%d]:%c,\tstr2[%d]:%c\n", i, str1[i], j, str2[j] );
			if(str1[i] == str2[j])
				count++;
		}
//		printf("Count:%d\n",count);
	}

	if(count == len)
		printf("String are anagrams.\n");
	else if(count != len)
		printf("String are not anagrams.\n");

	return 0;
}
