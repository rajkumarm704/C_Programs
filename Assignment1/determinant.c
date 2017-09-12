#include<stdio.h>
#include<stdlib.h>

int find_sign(int row, int col)
{
	int i, sign = 1;
	
	for( i = 0; i < row+col; i++)
		sign *= -1;

	printf("sign:%d\n",sign);

	return sign;
}


int main()
{

	system("clear");

	int rows, cols, i, j, sign;
	int det = 0, mul, mul1, mul2;

	printf("Enter the value of rows:");
	scanf("%d",&rows);

	printf("Enter the value of columns:");
	scanf("%d",&cols);

	int arr1[rows][cols], arr2[rows][cols];

	//Entering data into 2D array
	for ( i = 0; i < rows; i++)
		for ( j = 0; j < cols; j++)
			scanf("%d",&arr1[i][j]);

	//Displaying Original array
	printf("\nOriginal array is\n");
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
			printf("%d\t",arr1[i][j]);

		printf("\n");
	}

/*
	j

i	1	2	3	|	a00	a01	a02
	4	5	6	|	a10	a11	a12
	7	8	9	|	a20	a21	a22

*/

	if( rows == 3 && cols == 3 )
	{
		printf("3X3\n");

		//Finding determinant
		for( i = 0; i < 1; i++ )
		{
			for( j = 0; j < cols; j++ )
			{
				if( j == 0 )
				{
					mul1 = arr1[i + 1][j + 1] * arr1[i + 2][j + 2];
					mul2 = arr1[i + 1][j + 2] * arr1[i + 2][j + 1];
					mul = mul1 - mul2;
					sign = find_sign(i, j);
					mul *= sign;
					det += mul;
				}
				else if( j == 1 )
				{
					mul1 = arr1[i + 1][j - 1] * arr1[i + 2][j + 1];
					mul2 = arr1[i + 2][j - 1] * arr1[i + 1][j + 1];
					mul = mul1 - mul2;
					sign = find_sign(i, j);
					mul *= sign;
					det += mul;

				}
				else if( j == cols - 1 )
				{
					mul1 = arr1[i + 1][j - 2] * arr1[i + 2][j - 1];
					mul2 = arr1[i + 2][j - 2] * arr1[i + 1][j - 1];
					mul = mul1 - mul2;
					sign = find_sign(i, j);
					mul *= sign;
					det += mul;
				}	
			}
		}
	}
	else if( rows == 2 && cols == 2 )
	{
		printf("2X2\n");
		//Finding determinant
		for( i = 0, j = 0; i < 1; i++ )
		{
			if( j == 0 )
			{
				mul1 = arr1[i][j] * arr1[i + 1][j + 1];
				mul2 = arr1[i][j + 1] * arr1[i + 1][j];
				mul = mul1 - mul2;
				det += mul;
			}
		}
	}

	printf("Determinant:%d\n",det);

	printf("\n");

	return 0;
}
