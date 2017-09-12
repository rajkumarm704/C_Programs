#include<stdio.h>


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

	int rows, n, flag = 0;
	float element[100], sum = 0;
	int  i, j, k, limit = 0, index = 0;
	int avg_idx = 0, avg_arr_idx = 0;

	printf("Enter the number of rows:");
	scanf("%d",&rows);

	int element_count[rows];
	float avg_arr[rows];

	for ( i = 0; i < rows; i++ )
	{
		printf("Enter the number of elements of Row %d: ",i);0;
		scanf("%d",&element_count[i]);

		printf("Enter the elements of Row %d: ",i);

		//Entering elements in ith row
		for( j = 0; j < element_count[i]; j++ )
			scanf( "%f" , &element[index + j] );
		
		limit = avg_idx + element_count[i];

		//Calculating average fo ith row
		for( avg_idx; avg_idx < limit ; avg_idx++ )
			sum += element[avg_idx];

		avg_idx++;

		sum = sum / j;

		index += element_count[i] ;

		//Store average in  separate array	
		avg_arr[avg_arr_idx] = sum;
		avg_arr_idx++;

		element[limit] = sum;
		index++;

		sum = 0;
		limit = 0;

	}


	for( i = 0; i < rows ; i++ )
		limit += element_count[i];

	limit += rows;

	printf("The matrix is:\n\n");


	for( i = 0, j = 0, k = 0; i < limit; i++,k++ )
	{
		if( k  == element_count[j] + 1)
		{
			putchar('\n');
			j++;
			k = 0;
		}
		if( k == element_count[j] )
			printf("%f, ",element[i]);
		else
			printf("%d, ",(int)element[i]);


	}

	printf("\n");



	sort_arr(avg_arr, rows);

	printf("\nMain Function Sorted array is:");
	for( i = 0 ; i < rows; i++ )
		printf("%f, ",avg_arr[i]);

	printf("\n");

	
	
	return 0;
} 
