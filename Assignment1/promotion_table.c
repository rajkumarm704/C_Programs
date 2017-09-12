#include<stdio.h>
#include<limits.h>
int main()
{

/*
SCHAR_MAX,
UCHAR_MAX,
SHRT_MAX,
USHRT_MAX,
INT_MAX,
UINT_MAX,
LONG_MAX,
ULONG_MAX,
LLONG_MAX,
ULLONG_MAX
*/
	printf("Signed char\n");

	if(UCHAR_MAX>SCHAR_MAX)	
		printf("Unsigned char\n");
	if(SHRT_MAX>UCHAR_MAX)
		printf("Signed short\n");
	if(USHRT_MAX>SHRT_MAX)
		printf("Unsigned short\n");
	if(INT_MAX>USHRT_MAX)	
		printf("Signed int\n");
	if(UINT_MAX>INT_MAX)
		printf("Unsigned int\n");
	if(LONG_MAX>UINT_MAX)	
		printf("Signed long\n");
	if(ULONG_MAX>LONG_MAX)	
		printf("Unsigned long\n");
	if(LLONG_MAX>ULONG_MAX)	
		printf("Signed long long\n");
	if(ULLONG_MAX>LLONG_MAX)	
		printf("Unsigned long long\n");

	return 0;
}

/*
SCHAR_MAX,
UCHAR_MAX,
SHRT_MAX,
USHRT_MAX,
INT_MAX,
UINT_MAX,
LONG_MAX,
ULONG_MAX,
LLONG_MAX,
ULLONG_MAX
*/
