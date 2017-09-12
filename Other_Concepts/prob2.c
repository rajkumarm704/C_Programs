#include<stdio.h>
int main()
{
	char name[100];
	printf("Enter the name:");
	scanf("%10[a-s A-Z]",name);
	printf("Name is:%s\n",name);

	return 0;
}
