#include<stdio.h>
#include<stdlib.h>

struct Student
{
	int id;
	char name[20];
	char address[60];
};

void data(struct Student *s1)
{
	s1->id = 10;
	(*s1).id = 50;
}

int main()
{

	system("clear");
	
	struct Student s1;

	printf("%d\n",s1.id);
	data(&s1);

	printf("%d\n",s1.id);
	
	return 0;
}
