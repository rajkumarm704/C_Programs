#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

int my_printf(const char *str, ... )
{
	va_list ap;
	int i, len;
	static int count = 0;
	char cptr[100];
	len = strlen(str);

	va_start(ap, str);
	
	for(i = 0; str[i] != '\0' ; i++ )
	{
		if(str[i] == '%' && str[i + 1] == 'd' )
		{   
			sprintf(cptr,"%d", va_arg(ap, int));
			count += strlen(cptr);
			fputs(cptr, stdout);
			i++;
		}
		else if(str[i] == '%' && str[i + 1] == 'f' )
		{
			sprintf(cptr,"%lf", va_arg(ap, double));
			count += strlen(cptr);
			fputs(cptr, stdout);
			i++;
		}
		else if(str[i] == '%' && str[i + 1] == 'c' )
		{
			sprintf(cptr,"%c", va_arg(ap, int));
			count += strlen(cptr);
			fputs(cptr, stdout);
			i++;
		}
		else if(str[i - 1] == '%' && str[i] == 's' )
		{
			sprintf(cptr,"%s", va_arg(ap, char *));
			count += strlen(cptr);
			fputs(cptr, stdout);
		}		
		else if(str[i] == '%')
		{count++;}
		else
		{
			putchar(str[i]);
			count++;
		}
	}

	va_end(ap);
	return count-1;
}


int main()
{
	system("clear");

	float avg;
	int len;

	printf("\nmy_printf func\n");
	len = my_printf("Number:%d, character:%c, Float/Double:%f, String:%s Num:%d", 20, 'R', 2.3, "Raj Kumar", 22 );
	
	printf("\nlength:%d\n",len);

	printf("\nprintf func\n");
	len = printf("Number:%d, character:%c, Float/Double:%f, String:%s Num:%d", 20, 'R', 2.3, "Raj Kumar", 22 );

	printf("\nlength:%d\n",len);

	return 0;
}
