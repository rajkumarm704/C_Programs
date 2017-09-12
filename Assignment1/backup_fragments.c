#include<stdio.h>
#include<stdlib.h>
void cne();
void ubound();
void lbound();


void sort_arr(float *arr, int size)
{
	int i, j;
	float  temp[size], t = 0;



	for( i = 0 ; i < size; i++ )
		temp[i] = arr[i];

	int ii = 0;

	for( j = size - 1; j >= 0; j-- )
	{
		t = temp[j];

		for( i = 0 ; i < size; i++ )
		{
			if( t >= temp[i] )
			{
				t = t;
				arr[j] = t;
			}
			else if( temp[i] > t )
			{
				t = temp[i];
				arr[j] = t;
			}

		}

		for( ii = 0; ii < size; ii++)
		{
			if( temp[ii] == t )
				temp[ii] = 0;
		}
	}

/*	printf("\nSorted array is:");
	for( i = 0 ; i < size; i++ )
		printf("%f, ",arr[i]);

	printf("\n");
*/
	
}

int main()
{

	cne();
	ubound();

	int rows;
	printf("Enter the number of rows:");
	scanf("%d",&rows);

	void *marr[rows];
	int i, j, k, arr_ele[rows],temp = 0;
	float sum = 0, avg_arr[rows], temp2 = 0;;
	

	for( i  = 0; i < rows; i++ )
	{
		printf("\nEnter the number of elements in Row %d: ",i);
		scanf("%d",&arr_ele[i]);

		marr[i] = malloc( (arr_ele[i] + 1) * sizeof(int) );

		printf("Enter the elements:");		
		for( j = 0; j < arr_ele[i]; j++ )
		{
			scanf("%d", &temp );
			*( ( (int *)( marr[i] ) + j ) ) = temp;
			sum += temp;
		}	
		
		sum /= j;
//		printf("Average:%f\n",sum);
		*( ( (float *) ( marr[i] ) + arr_ele[i] + 1 ) ) = sum;
		avg_arr[i] = sum;

		printf("Array is:");
		for( j = 0; j < arr_ele[i] ; j++ )
			printf("%d, ", *( ( (int *) ( marr[i] ) + j ) ) );

		printf("%f",*( ( float * )( marr[i] ) + j + 1 ) );


		printf("\n\n");

		sum = 0;
	}
	
	sort_arr(avg_arr, rows);

	printf("Average array is:");
	for ( i = 0; i < rows; i++ )
		printf("%f, ", avg_arr[i]);

	printf("\n\n");


	printf("Start\n");

	temp = 0;

	for ( i = 0; i < rows; i++ )
	{
		printf("arr_ele:%d\n",arr_ele[i]);
		temp += arr_ele[i];
	}

	temp += rows;
	printf("temp:%d\n",temp);

	for ( i = 0; i < rows ; i++ )
		for( j = 0; j < arr_ele[i]; j++ )
			printf("%f, ",*( (int *)( marr[i] ) +j ) );

	printf("\nStop\n");

	printf("Final Output array is:\n\n");

	int index, z;

	for ( i = 0; i < rows; i++ )
	{
		for ( j = 0; j < rows; j++ )
		{
			index = arr_ele[j] + 1;

			temp2 = *( (float *)( marr[j] ) + index ) ;
			printf("i:%d, j:%d, average:%f, temp2:%f, index:%d\n", i, j, avg_arr[i], temp2, index);

			if ( avg_arr[i] == temp2 )
			{
//				printf("\n");
				for ( k = 0; k < arr_ele[j]; k++ )
					printf("%d, ", *( (int *)( marr[j] ) + k ));

				printf("%f", *( (float *)( marr[j] ) + k + 1 ) );
				printf("\n");
			}

		}



	printf("\n\n");

	}
			


	printf("\n");

	lbound();

	return 0;
}

void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc fragments.c -o fragments.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}

