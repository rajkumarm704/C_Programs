#include<stdio.h>
#include<stdlib.h>

//#define SIZEOF(x) sizeof(x)

#define SIZEOF1(x) ( (char *)(&x + 1) - (char *)(&x) )
//#define SIZEOF2(x) ( (int *)(&x + 1) - (int *)(&x) )
//#define SIZEOF3(x) ( (double *)(&x + 1) - (double *)(&x) )

int main()
{
	system("clear");

	int x; int y[10]; float f; double d; long l;
	
	printf("Size of x is %d\n",SIZEOF1(x) );
	printf("Size of y is %d\n",SIZEOF1(y) );
	printf("Size of f is %d\n",SIZEOF1(f) );
	printf("Size of d is %d\n",SIZEOF1(d) );
	printf("Size of l is %d\n",SIZEOF1(l) );
/*	printf("\n");
	printf("Size of x is %d\n",SIZEOF2(x) );
	printf("Size of y is %d\n",SIZEOF2(y) );
	printf("Size of f is %d\n",SIZEOF2(f) );
	printf("Size of d is %d\n",SIZEOF2(d) );
	printf("Size of l is %d\n",SIZEOF2(l) );
	printf("\n");
	printf("Size of x is %d\n",SIZEOF3(x) );
	printf("Size of y is %d\n",SIZEOF3(y) );
	printf("Size of f is %d\n",SIZEOF3(f) );
	printf("Size of d is %d\n",SIZEOF3(d) );
	printf("Size of l is %d\n",SIZEOF3(l) );
*/

	return 0;
}

