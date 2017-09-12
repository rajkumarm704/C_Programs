/**	Pointer to structure 	**/

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

	struct Student s1 = { 750, "Yoo mann!!!", "India.`.`.`.`." };
	struct Student *sptr;

	sptr = &s1;

/*	printf("Value of sptr->id\t: %d\n"
		"Value of sptr->name\t: %s\n"
		"Value of sptr->address\t: %s \n\n",sptr->id, sptr->name, sptr->address);
*/

	printf("Value of (*sptr).id\t\t: %d\n"
		"Value of (*sptr).name\t\t: %s\n"
		"Value of (*sptr).address\t: %s \n\n",(*sptr).id, (*sptr).name, (*sptr).address);


/*	printf("Value of sptr->id\t: %d \n",sptr->id);
	printf("Value of sptr->name\t: %s \n",sptr->name);
	printf("Value of sptr->address\t: %s \n\n",sptr->address);
*/
	return 0;
}
