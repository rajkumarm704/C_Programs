#include<stdio.h>
int main()
{
	int char_count,char_count_copy;
	printf("Enter the number of characters: ");
	scanf("%d",&char_count);
	char char_arr[char_count];
	char_count_copy=char_count;
	printf("\nEnter %d characters: ",char_count);
	int i;
	for(i=0;i<char_count;i++)
	{
		scanf("%c",&char_arr[i]);
	}
	for(i=0;i<char_count_copy;i++)
	{
		printf("The characters are %c \n",char_arr[i]);
	}
return 0;
}

