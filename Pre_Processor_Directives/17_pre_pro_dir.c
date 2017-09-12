#include<stdio.h>
#include<stdlib.h>

#define PRINT(str) printf(#str ": %d\n", str)
#define PRINTS(str) printf(#str ": %s\n", str)

int main()
{
	system("clear");

	int x = 2, y = 3;
	PRINT(x);
	PRINT(y);
	PRINTS(__FILE__);

	return 0;
}

