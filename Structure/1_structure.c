/**		Introduction to structures	**/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct Student
{
	int id;
	char name[20];
	char address[60];
};

int main()
{

	system("clear");

	struct Student s1;
	s1.id = 10;

	printf("Enter name:"),scanf("%[^\n]", s1.name);
	__fpurge(stdin);
	printf("Enter address:"),scanf("%[^\n]", s1.address);


	printf("size of Student is %d \n",sizeof(struct Student) );
	printf("size of Student is %d \n\n",sizeof(s1) );

	printf("Address of s1\t\t: %p \n",&s1);

	printf("Address of s1\t\t: %d \n",(char*)(&s1 + 1) - (char *)(&s1) );

	printf("Address of s1.id\t: %p \n",&s1.id);
	printf("Address of s1.name\t: %p \n",&s1.name);
	printf("Address of s1.address\t: %p \n\n",&s1.address);

	printf("Value of s1.id: %d \n\n",s1.id);
	printf("Value of s1.name\t: %s \n",s1.name);
	printf("Value of s1.address\t: %s \n\n",s1.address);


	return 0;
}
