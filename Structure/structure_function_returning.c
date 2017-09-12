#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct Student
{
	int id;
	char name[20];
	char address[60];
};


struct Student * get_student(void)
{
	static struct Student s1;
	
	printf("Enter id:"),scanf("%d", &s1.id);
//	__fpurge(stdin);
	printf("Enter name:"),scanf("\n%[^\n]", s1.name);
//	__fpurge(stdin);
	printf("Enter address:"),scanf("\n%[^\n]", s1.address);

	return &s1;
}

int main()
{

	system("clear");

	struct Student *s1;

	s1 = get_student();

	printf("Value of (*s1).id\t: %d \n",(*s1).id);
	printf("Value of (*s1).name\t: %s \n",(*s1).name);
	printf("Value of (*s1).address\t: %s \n\n",(*s1).address);

	return 0;
}
