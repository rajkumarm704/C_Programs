#include<stdio.h>
int main()
{

	int a;
	printf("Enter the value: ");
	scanf("%d",&a);
	switch(a)
	{
/*		case '0' ... '9':printf("You have entered number.\n");break;
		case 'A' ... 'Z':printf("You have entered Uppercase Alphabets.\n");break;
		case 'a' ... 'z':printf("You have entered Lowercase Alphabets.\n");break;
*/
		case 0 ... 9 :printf("You have entered number.\n");break;
		case 'A' ... 'Z':printf("You have entered Uppercase Alphabets.\n");break;
		case 'a' ... 'z':printf("You have entered Lowercase Alphabets.\n");break;
		default:printf("You have entered Special Charater.\n");break;
	}
	return 0;
}
