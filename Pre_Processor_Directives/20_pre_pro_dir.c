#include<stdio.h>
#include<stdlib.h>

//#define METHOD1

int main()
{
	system("clear");

	#ifdef METHOD1
		puts("puts is used\n");
	#endif
	#if defined METHOD2
		printf("printf is used\n");
	#endif
	#if defined (METHOD1) &&  (METHOD2)
		puts("\nputs is used");
		printf("printf is used\n");
	#endif

/*	#ifdef METHOD1
		puts("puts is used\n");
	#else
		printf("printf is used\n");
	#endif
*/
	return 0;
}

