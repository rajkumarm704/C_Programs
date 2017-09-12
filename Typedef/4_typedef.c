#include<stdio.h>
#include<stdlib.h>

typedef struct _Student
{
	int id;
	char name[30];
	char address[150];
}Student;

void data(Student *s)
{
	s->id = 10;
}

int main()
{

	system("clear");

	Student s1;
	data(&s1);

	printf("s1.id:%d\n",s1.id);

	return 0;
}
