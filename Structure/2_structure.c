/**		Ways to assign data to structure		**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

static struct Student
{
	int id;
	char name[20];
	char address[60];
};

int main()
{

	system("clear");

	struct Student s1 = { 56, "Raj Kumar", "Bangalore" };

/*	Input from Key Board

	printf("Enter id:"),scanf("%d", s1.id);
	printf("Enter name:"),scanf("%[^\n]", s1.name);
	__fpurge(stdin);
	printf("Enter address:"),scanf("%[^\n]", s1.address);
*/
/*
	s1.id = 99;
	strcpy(s1.name, "Raj Kumar");
	strcpy(s1.address, "Bangalore");
*/

	

	printf("Value of s1.id\t\t: %d \n",s1.id);
	printf("Value of s1.name\t: %s \n",s1.name);
	printf("Value of s1.address\t: %s \n\n",s1.address);


	return 0;
}
