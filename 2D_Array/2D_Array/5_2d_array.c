/************************PICTORIAL REPRESENTATION******************************************

	mptr = malloc(row*sizeof(int *) );	//Storing Row Address
	   |
	   | 		   for( i = 0; i < 2; i++ )	//Storing Column Address
	   |		      mptr[i] = malloc( col * sizeof(int) );
	   |		           |
	   V			   V
	 ________	   _____   _____   _____
  R1	|  1000  | -----> |  C1	| |  C2	| |  C3	| 
	 ````````	   `````   `````   `````
	 mptr[0]	   (1000)  (1004)  (1008)		
	 (5000)
	 ________	   _____   _____   _____
  R2	|  2000  | -----> |  C1	| |  C2	| |  C3	|
	 ````````	   `````   `````   `````
	 mptr[1]	   (2000)  (2004)  (2008)
	 (5004)
 
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");

	int i, j, row = 2, col = 3;
	int **mptr;

	//Storing address of rows
	mptr = malloc(row*sizeof(int *) );	

	//Storing address of columns
	for( i = 0; i < row; i++ )
		mptr[i] = malloc( col * sizeof(int) );

	printf("Enter values:");

	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < col; j++ )
		{
			scanf("%d",&mptr[i][j]);
		}
	}


	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < col; j++ )
		{
			printf("%d ",mptr[i][j]);
		}
		printf("\n");
	}


	return 0;
}
	
