#include<stdio.h>
#include<stdlib.h>
#include"generic_sort_search.h"

void find_mean(void *vptr, int n, int data_type)
{
	int i;
	void *temp;

	switch(data_type)
	{
		case 1:
			temp = malloc( sizeof(float) );
			for( i = 0; i < n; i++ )
				*( (float *)temp ) += *( (int *)vptr + i );
			*( (float *)temp ) /= n;
			printf("The mean is %.2f\n", *( (float *)temp ) );
			break;
		case 2:
			temp = malloc( sizeof(float) );
			for( i = 0; i < n; i++ )
				*( (float *)temp ) += (int)*( (char *)vptr + i );
			*( (float *)temp ) /= n;

			printf("The mean is %c (int:%d, float:%.2f) \n", (int)*( (float *)temp ), (int)*( (float*)temp), *( (float *)temp ) );
			break;
		case 3:
			temp = malloc( sizeof(float) );
			for( i = 0; i < n; i++ )
				*( (float *)temp ) += *( (float *)vptr + i );
			*( (float *)temp ) /= n;			
			printf("The mean is %.2f\n", *( (float *)temp ) );
			break;
	}
}

int main()
{

	system("clear");
	int option, n;
	void *vptr;
	printf("Choose a Data Type:\n1. Integer\n2. Character\n3. Float\nYour option: ");
	scanf("%d",  &option);

	printf("Enter the number of elements:"),scanf("%d", &n);
	
	printf("Enter the elements:");

	vptr = read_data(vptr, n, option);

	find_mean(vptr, n, option);

	return 0;
}
