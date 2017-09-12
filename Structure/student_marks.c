#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct Student
{
	int phy, chem, maths;
	char name[50];

};

int main()
{

	system("clear");
	
	int n, i;

	printf("Enter the number of students:"), scanf("%d", &n);

	struct Student sarr[n];
	float avg[n];

	for( i = 0; i < n; i++ )
	{
		__fpurge(stdin);
		printf("Enter name:"), scanf("%[^\n]",sarr[i].name);
		printf("Enter Physics marks:"), scanf("%d",&sarr[i].phy);
		printf("Enter Chemistry marks:"), scanf("%d",&sarr[i].chem);
		printf("Enter Maths marks:"), scanf("%d",&sarr[i].maths);

		avg[i] = ( sarr[i].phy + sarr[i].chem + sarr[i].maths )/3;

		printf("Your average is %f\n", avg[i] );
	}

	printf(" ___________________________________________________________________________\n");
	printf("|%20s|%-10s|%-10s|%-10s|%-10s|\n", "STUDENT\t\t", "PHYSICS", "CHEMISTRY", "MATHS", "AVERAGE" );

	for(i = 0; i < n; i++ )
	{
	printf(" ---------------------------------------------------------------------------\n");
		printf("|\t%-20s\t|%-10d|%-10d|%-10d|%-10.2f|\n",sarr[i].name, sarr[i].phy, sarr[i].chem, sarr[i].maths, avg[i]);
	}

	printf(" ```````````````````````````````````````````````````````````````````````````\n");
	return 0;
}
