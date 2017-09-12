#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

int my_scanf(const char *str, ... )
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
			printf("int:");
			fscanf(stdin,"%d", va_arg(ap, int* ));
			count ++;
			__fpurge(stdin);
		}
		else if(str[i] == '%' && str[i + 1] == 'f' )
		{
			printf("float:");
			fscanf(stdin,"%f", va_arg(ap, float* ));
			count ++;
			__fpurge(stdin);
		}
		else if(str[i] == '%' && str[i + 1] == 'c' )
		{
			printf("char:");
			fscanf(stdin,"%c", va_arg(ap, char* ));
			count ++;
			__fpurge(stdin);
		}
		else if(str[i - 1] == '%' && str[i] == 's' )
		{
			printf("string:");
			fscanf(stdin,"%s", va_arg(ap, char* ));
			count ++;
			__fpurge(stdin);
		}		
	}

	va_end(ap);
	return count;
}


int main()
{
	system("clear");

	float fnum;
	int len;
	
	int a, b;
	char ch;
	char carr[100];

	printf("\nmy_scanf func\n");
	len = my_scanf("%d %f %c %s", &a, &fnum, &ch, carr);
	
	printf("result: %d %f %c %s\n", a, fnum, ch, carr );

	printf("\nlength:%d\n",len);

	printf("\nscanf func\n");
	len = scanf("%d %f %c %s", &a, &fnum, &ch, carr);
	printf("result: %d %f %c %s\n", a, fnum, ch, carr );
	printf("\nlength:%d\n",len);

	return 0;
}
