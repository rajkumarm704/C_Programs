#ifndef STUDENT_H
#define STUDENT_H

#pragma pack(1)

#define NAME_LEN 64

typedef struct Student
{
	char name[NAME_LEN];
	int p, c, m;
}student_t;

#endif
