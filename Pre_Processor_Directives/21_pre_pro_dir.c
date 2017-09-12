#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");

	#if METHOD == 1
		puts("puts is used\n");
	#endif
	#if METHOD == 2
		printf("printf is used\n");
	#endif

	return 0;
}

