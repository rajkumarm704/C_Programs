#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define MAX 3

float avg[MAX];

//Structure Declaration
struct Student
{
	int phy, chem, maths;
	char name[50];

};

//Reading Input 
void read_student_marks(struct Student (*sarr)[], int n)
{
	int i;

	for( i = 0; i < n; i++ )
	{
		__fpurge(stdin);
		printf("Enter name:"), scanf("%[^\n]",(*sarr)[i].name);
		printf("Enter Physics marks:"), scanf("%d",&(*sarr)[i].phy);
		printf("Enter Chemistry marks:"), scanf("%d",&(*sarr)[i].chem);
		printf("Enter Maths marks:"), scanf("%d",&(*sarr)[i].maths);

		avg[i] = ( (*sarr)[i].phy + (*sarr)[i].chem + (*sarr)[i].maths )/3;
		printf("Your average is %f\n", avg[i] );
	}

}

//Displaying Result
void print_student_marks(struct Student (*sarr)[], int n)
{

	int i;

	printf(" ___________________________________________________________________________\n");
	printf("|%20s|%-10s|%-10s|%-10s|%-10s|\n", "STUDENT\t\t", "PHYSICS", "CHEMISTRY", "MATHS", "AVERAGE" );

	for(i = 0; i < n; i++ )
	{
	printf(" ---------------------------------------------------------------------------\n");
		printf("|\t%-20s\t|%-10d|%-10d|%-10d|%-10.2f|\n",(*sarr)[i].name, (*sarr)[i].phy, (*sarr)[i].chem, (*sarr)[i].maths, avg[i]);
	}

	printf(" ```````````````````````````````````````````````````````````````````````````\n");
}

//Main Function
int main()
{

	system("clear");
	
	struct Student sarr[MAX];

	read_student_marks(&sarr, MAX);

	print_student_marks(&sarr, MAX);

	return 0;
}


