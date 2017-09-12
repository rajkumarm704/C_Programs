#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

	printf("Size of FILE: %d\n",sizeof(FILE) );

	printf("stdin address: %p\n", stdin );
	printf("stdout address: %p\n", stdout );
	printf("stderr address: %p\n", stderr );

#if 0
	printf("stdin file descripter: %d\n", stdin->_fileno );
	printf("stdout file descripter: %d\n", stdout->_fileno );
	printf("stderr file descripter: %d\n", stderr->_fileno );	
#else
	printf("stdin file descripter: %d\n", fileno(stdin) );
	printf("stdout file descripter: %d\n", fileno(stdout) );
	printf("stderr file descripter: %d\n", fileno(stderr) );	
#endif
	return 0;
}
