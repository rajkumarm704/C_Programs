/*******************CHANGE INPUT AND OUTPUT FILENAME***************/

#include<stdio.h>

void cne();
void ubound();
void lbound();


int main()
{

	cne();
	ubound();

	int n, i, t, ii, count = 0, j,t2;
	printf("Enter the number of elements:");
	scanf("%d",&n);

	int arr[n];

	printf("Enter the elements:");

	for ( i = 0; i < n; i++ )
		scanf("%d",&arr[i]);	


	for ( i = 0; i < n; i++ )
	{
		t = arr[i];

		for( j = i; j < n ; j++ )
		{
			if( arr[j] < t )
			{
				count = j;
				t = arr[j];
			}
		}

		if( count != 0 )
		{
			t2 = arr[i];
			arr[i] = arr[count];
			arr[count] = t2;
		}

		count = 0;
	}
	

	printf("Sorted array is:");
	for ( i = 0; i < n; i++ )
		printf("%d, ",arr[i]);	
	printf("\n");

	lbound();
	return 0;
}


void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc selection_sort.c -o selection_sort.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}

