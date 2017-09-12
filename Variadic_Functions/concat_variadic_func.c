#include<stdio.h>				//Date:30th June, 2017
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

//Customised string concatination function
//Always add null character('\0') at the end of string
char *mystrcat(char *dest, char *src)
{
	int i, j, count = 0;

	count = strlen(src) + strlen(dest);

	for( i = strlen(dest), j = 0; i < count; i++, j++ )
		dest[i] = src[j];

	dest[i] = '\0';

	return dest;	
}

//Variadic function for string concatination
char *concat_vf(char *buff, const char *str, ... )
{
	va_list args;
	int i, count;
	
	char temp[200];
	va_start(args, str);
	count = strlen(str);
	buff[0] = '\0';

	for(i = 0; i < count; i++ )
		if(str[i - 1] == '%' && str[i] == 's'  )
			mystrcat(buff,va_arg(args, char*));

	va_end(args);
	return buff;
}


int main()
{
	system("clear");

	char dest[200] = "Hey!", *ptr;
	char str[200] = "Hello World!";
	
	ptr = concat_vf(dest, "%s", str );
	
	if(ptr)
		printf("%s\n", ptr);

	dest[0] = '\0';
	ptr = concat_vf(dest, "%s %s %s", "How ", "are ", "you?" );

	if(ptr)
		printf("%s\n", ptr);

	return 0;
}
