#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

void my_printf(const char *str, ... )
{
	va_list ap;
	int i, len, count = 0;

	len = strlen(str);

	va_start(ap, str);
	
	for(i = 0; str[i] != '\0' ; i++ )
	{
		if(str[i] == '%' && str[i + 1] == 'c' )
		{
			printf("%c",va_arg(ap, int) );		
			i++;
		}
		else if(str[i - 1] == '%' && str[i] == 's' )
		{
			printf("%s",va_arg(ap, char*) );		
			i++;
		}
		else if(str[i - 1] == '%' || str[i] == '%')
		{}
		else
			printf("%c",str[i]);
	}


	va_end(ap);
}


int main()
{
	system("clear");

	float avg;

	my_printf("Character:%c, String:%s", 'R', "Raj kumar" );
	
	printf("\n");

	return 0;
}
