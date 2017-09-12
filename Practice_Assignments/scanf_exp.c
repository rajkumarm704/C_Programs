#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

	char buffer[100];

	printf("Enter the string:");
	scanf("%*[\n] %[^\n]", buffer);

	printf("buffer: %s\n", buffer);

	return 0;
}
