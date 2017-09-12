#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include<stdio_ext.h>

#define MAX_STUDENTS 3

void print_student_info(student_t *s, int scount)
{
	int i;
	float msum, psum, csum;
printf(" ------------------------------------------------------------------\n");
printf("|%-20s\t|%-10s\t|%-10s\t|%-10s|\n", "Name", "Physics", "Chemistry", "Maths");
printf(" ------------------------------------------------------------------\n");
	for(i = 0; i < scount; i++ )
	{
		printf("|%-20.20s\t|%-10d\t|%-10d\t|%-10d|\n", s[i].name, s[i].p, s[i].c, s[i].m);
		psum += s[i].p;
		csum += s[i].c;
		msum += s[i].m;
	}
printf(" ------------------------------------------------------------------\n");
printf("|%-20.20s\t|%-10.2f\t|%-10.2f\t|%-10.2f|\n", "Average", psum/scount, csum/scount, msum/scount);
printf(" ------------------------------------------------------------------\n");


}

int main(int argc, char *argv[] )
{
	system("clear");

	FILE *fp = NULL;

	student_t slist[MAX_STUDENTS];

	if( argc < 2)
	{
		printf("Invalid arguments\n");
		return 1;
	}

	fp = fopen(argv[1], "r");

	if( NULL == fp )
	{
		perror("");
		printf("Error! File %s could not be opened\n", argv[1] );
		return 2;
	}

	fread(slist, sizeof(student_t), MAX_STUDENTS, fp);

	print_student_info(slist, MAX_STUDENTS);

	fclose(fp);

	return 0;
}
