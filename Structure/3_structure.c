/**		Copying a structure to another variable		**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

	struct Student s1 = { 56, "Raj Kumar", "Bangalore" };
	struct Student s2;

	s2 = s1;

	printf("Value of s2.id\t\t: %d \n",s2.id);
	printf("Value of s2.name\t: %s \n",s2.name);
	printf("Value of s2.address\t: %s \n\n",s2.address);


	return 0;
}
