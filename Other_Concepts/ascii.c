#include<stdio.h>
int main()
{
	char c;
	printf("Enter the characcter: ");
	scanf("%c",&c);
	if(c>=65 && c<=90)
		printf("The character entered is a Uppercase Alphabet.\n");
	else if(c>=97 && c<=122)
		printf("The character entered is a Lowercase Alphabet.\n");
	else if(c>=30 && c<=39)
		printf("The character entered is a Number\n.");
	else
		printf("The character entered is a Special Character.\n");
return 0;
}
