#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include<stdio_ext.h>

#define MAX_STUDENTS 3

void get_student_info(student_t *s, int scount)
{
	int i;
	for(i = 0; i < scount; i++ )
	{
		printf("Enter the name of student:"), scanf("%[^\n]", s[i].name);
		printf("Enter P, C, M marks:");
		scanf("%d %d %d", &s[i].p, &s[i].c, &s[i].m);
		__fpurge(stdin);
	}
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

	fp = fopen(argv[1], "w");

	if( NULL == fp )
	{
		perror("");
		printf("Error! File %s could not be opened\n", argv[1] );
		return 2;
	}

	get_student_info(slist, MAX_STUDENTS);

	fwrite(slist, sizeof(student_t), MAX_STUDENTS, fp );

	fclose(fp);

	return 0;
}
