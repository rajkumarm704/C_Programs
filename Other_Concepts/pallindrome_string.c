#include<stdio.h>

int strlen_func(char *str)
{
	int i;
	for( i = 0; str[i] != '\0'; i++);

	return i;
}

void main()
{
	char str[100];
	int count, i, j, scount = 0, count_t;

	printf("Enter a string:");
	scanf("%s",str);

	count = strlen_func(str);
	count_t = count;
	count = ( count%2 == 0 )? ( count / 2 ) : ( count + 1 ) / 2 ;

	for( i = 0, j = count_t-1; i < count; i++, j--)
	{	printf("str[%d]:%c, str[%d]:%c\n",i,str[i],j,str[j]);
		if( str[i] == str[j])
			scount++;	
	}

	if(scount == count )
		printf("The string is pallindrome.\n");
	else	
		printf("The string is not pallindrome.\n");

}
