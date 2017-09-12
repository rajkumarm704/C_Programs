#include<stdio.h>

void strcpy_func(char *src, char *dst, int n)
{
	int i;
	for(i = 0; i < n; i++)
		dst[i] = src[i];

	dst[i] = '\0';
	
}

void main()
{
	int n;
	char src[100],dst[100];
	printf("Enter first string:");
	scanf("%s",src);

/*	printf("Enter second string:");
	scanf("%s",dst);
*/
	printf("Enter number of charactes to copy:");
	scanf("%d",&n);
	

	strcpy_func(src,dst,n);

	printf("First string:%s\nSecond string:%s\n",src,dst);
}
