#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

	//Variable declaration
	int n, i;

	//for dynamic memory allocation of string
	char *mptr;

	//Stores the string 
	char temp[50];

	//Used to calculate the length of string so that apropriate memory can be allocated
	int len;

	//Index for de-allocating memory
	int j;

	//Used for swapping strings
	char *tdata;

	//Used for storing base address of all strings
	char *data[n];

	printf("Enter the number of names:");
	scanf("%d",&n);


	for( i = 0; i < n; i++ )
	{
		printf("Enter name %d:", i);

		//Store string in temp variable
		scanf("%s",temp);

		//Clear buffer
		while(getchar() != '\n');

		//Findout the length of string and increment by one to store null character
		len = strlen(temp);
		len++;

		//Allocate memory to store string
		mptr = malloc(len);

		//Copy the string from temp varaiable to allocated memory
		strcpy(mptr,temp);

		//Store the ith base address in character array pointer
		data[i] = mptr;

	}

	//Print unsorted array
	printf("unsorted string is: ");
	for( i = 0; i < n; i++ )
		printf("%s, ",data[i] );

	printf("\n");

	//Perform Bubble Sort
	for( j = 0; j < n; j++ )
	{		
		for( i = 1; i < n; i++ )
		{
		//If (i - 1)th string is greater than ith string; Perform swapping operation
			if( strcmp(data[ i - 1 ],data[ i ] ) > 0 )
			{
				tdata = data[ i ];
				data[ i ] = data[ i - 1 ];
				data[ i - 1 ] = tdata;
			}
		}
	}

	//Print sorted array
	printf("sorted string is: ");
	for( i = 0; i < n; i++ )
		printf("%s, ",data[i] );

	printf("\n");

	//Free memory
	for( i = 0; i < n; i++ )
		free( data[ i ] );		

	return 0;
}

