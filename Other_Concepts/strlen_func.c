#include<stdio.h>
int strlen_func(char *arr)
{
	int count=0,i=0;
	char *index=arr-1;
	printf("Called Function\n");
	printf("size of string:%d\n\n",*index);	
	while(arr[i]!=0)
	{
		count++;
		i++;
	}
	return count;
}

int main()
{
	char str[10]="hello";
	int len;
	char *add;

	add=str-1;
	*add=sizeof(str)/sizeof(*str);

	printf("Main Function\n");
	printf("size of string:%d\n\n",sizeof(str)/sizeof(*str));

	len=strlen_func(str);
	printf("The length of string is:%d\n",len);
	return 0;
}
