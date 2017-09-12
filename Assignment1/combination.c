#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{

	system("clear");

	char str[100];
	int i,j,count;
	
	printf("Enter first string:");
	scanf("%s",str);

	count = strlen(str);
	char strcom[count + 1];

	for( i = 0; i < count; i++ )
	{
		for( j = 0; j < count; j++ )
		{
			if( i == j)
			continue;
			printf("%c%c\n",str[i],str[j]);
		}
	}

}
