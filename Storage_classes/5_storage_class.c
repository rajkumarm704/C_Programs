#include<stdio.h>
int main()
{
	int j = 0;

	{
		int j = 10;
		printf("j:%d\n",j);
	}
	
	printf("j:%d\n",j);
	return 0;
}
