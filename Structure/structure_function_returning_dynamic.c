#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct Student
{
	int id;
	char *name;
	char *address;
};


struct Student * get_student(void)
{
	struct Student *s1 = malloc( sizeof(struct Student) );

	s1->name =  malloc(30 * sizeof(char));
	s1->address =  malloc(50 * sizeof(char));
	
	
/* Terminal Input
	printf("Enter id:"),scanf("%d", &s1->id);
	__fpurge(stdin);
	printf("Enter name:"),scanf("%[^\n]", (*s1).name);
	__fpurge(stdin);
	printf("Enter address:"),scanf("%[^\n]", (*s1).address);
*/
/* File Input */
	printf("Enter id:"),scanf("%d", &(*s1).id);
	printf("Enter name:"),scanf("\n%[^\n]", (*s1).name);
	printf("Enter address:"),scanf("\n%[^\n]", (*s1).address);


	return s1;
}

int main()
{

	system("clear");

	struct Student *s1;

	s1 = get_student();

	printf("\n\nValue of (*s1).id\t: %d \n",(*s1).id);
	printf("Value of (*s1).name\t: %s \n",(*s1).name);
	printf("Value of (*s1).address\t: %s \n\n",(*s1).address);

	return 0;
}
