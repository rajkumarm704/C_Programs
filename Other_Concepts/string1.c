#include<stdio.h>
int main()
{
	int size=5,i;
	char name[5];

	name[0]='h';
	name[1]='i';
	name[2]='\0';
	name[3]='q';

	printf("The string is: %s\n",name);

	for (i = 0; i < size; i++)
	{
		printf("char[%d]: %d\n",i,name[i]);
	}

	printf("\nDone.\n");

	return 0;
}
