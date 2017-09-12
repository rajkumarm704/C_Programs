#include<stdio.h>
int main()
{

	int a;
	printf("Enter the value: ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:printf("You have entered 1.\n");//break;
		case 0x0C:printf("You have entered hex 12.\n");//break;
		case 010:printf("You have entered octal 8.\n");//break;
		case 0b0010:printf("You have entered binary 2.\n");//break;
		case 'A':printf("You have entered A.\n");break;
		default:printf("You have entered value greater than 5 or less than 1.\n");break;
	}
	return 0;
}
