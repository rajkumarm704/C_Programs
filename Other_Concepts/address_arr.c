#include<stdio.h>
int main()
{

	int i,j;
	int arr1[5];

	for(i=0;i<5;i++)
	{
		printf("%p, ",&arr1[i]);
	}
		printf("\n");
	return 0;
}
