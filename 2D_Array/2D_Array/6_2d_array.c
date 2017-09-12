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

int (*get_2d_array(void))[3]
{
	static int arr[2][3] = { 10, 20, 30, 40, 50, 60 };
	return arr;
}


int main()
{
	system("clear");

	int i, j, row = 2, col = 3;
	int (*ptr)[col];

	ptr = get_2d_array();

	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < col; j++ )
		{
			printf("%d ",ptr[i][j]);
		}
		printf("\n");
	}


	return 0;
}
	
