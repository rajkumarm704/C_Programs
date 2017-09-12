#include<stdio.h>

int strlen_func(char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++);
	
	return i;
}

void strcat_func(char *src, char *dst, int n)
{
	int i, j, count;
	count = strlen_func(src);


	for(i = count, j = 0; j < n && dst[j] != '\0'; i++, j++)
		src[i] = dst[j];

	src[i] = '\0';
	
}

void main()
{
	int n;
	char src[100],dst[100];

	printf("Enter first string:");
	scanf("%s",src);

	printf("Enter second string:");
	scanf("%s",dst);

	printf("Enter number of charactes to copy:");
	scanf("%d",&n);


	strcat_func(src,dst,n);

	printf("Complete string:%s\n",src);
}
