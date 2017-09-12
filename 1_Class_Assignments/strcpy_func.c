#include<stdio.h>

//void strcpy_func(char *src, char *dst)
char * strcpy_func(char *src, char *dst)
{
	char *t = src;

	while( *dst++ = *src++);

	return t;

/*	int i;
	for(i = 0; src[i] != '\0'; i++)
		dst[i] = src[i];

	dst[i] = '\0';
*/	
}

void main()
{
	char src[100],dst[100], *p;
	printf("Enter first string:");
	scanf("%s",src);

	printf("Enter second string:");
	scanf("%s",dst);


//	strcpy_func(src,dst);
	p = strcpy_func(src,dst);

	printf("First string:%s\nSecond string:%s\n",p,dst);
}
