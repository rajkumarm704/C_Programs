#include<stdio.h>
#include<stdlib.h>

#define WARN_IF(exp, x)						\
do								\
{								\
	x--;							\
	if(exp)							\
		fprintf(stderr, "Warning:" #exp "\n" );		\
	else							\
		printf("No Problemo.\n");				\
}								\
while(x);


int main()
{
	system("clear");
	int y = 5;

	WARN_IF( y == 0, y)

	return 0;
}

