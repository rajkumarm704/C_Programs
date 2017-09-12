#include<stdio.h>
#include<stdlib.h>

int find_sign(int row, int col)
{
	int i, sign = 1;
	
	for( i = 0; i < row+col; i++)
		sign *= -1;

//	printf("sign:%d\n",sign);

	return sign;
}


int main()
{

	system("clear");	

	int rows1, cols1, rows2, cols2, i, j, k, option, sign;
	int det = 0, mul, mul1, mul2, sum = 0;
	char ch;

	//Matrix 1
	printf("Enter the value of rows for matrix 1:");
	scanf("%d",&rows1);

	printf("Enter the value of columns for matrix 1:");
	scanf("%d",&cols1);

	//Matrix 2
	printf("Enter the value of rows for matrix 2:");
	scanf("%d",&rows2);

	printf("Enter the value of columns for matrix 2:");
	scanf("%d",&cols2);


	int arr1[rows1][cols1], arr2[rows2][cols2], arr[rows1][cols2];


	printf("Enter first matrix:\n");

	//Input matrix 1
	for ( i = 0; i < rows1; i++)
		for ( j = 0; j < cols1; j++)
			scanf("%d",&arr1[i][j]);


	printf("Enter second matrix:\n");

	//Input matrix 2
	for ( i = 0; i < rows2; i++)
		for ( j = 0; j < cols2; j++)
			scanf("%d",&arr2[i][j]);

	printf("\nMatrix 1 is\n");
	for ( i = 0; i < rows1; i++)
	{
		for ( j = 0; j < cols1; j++)
			printf("%d\t",arr1[i][j]);

		printf("\n");
	}

	printf("\n");

	printf("\nMatrix 2 is\n");
	for ( i = 0; i < rows2; i++)
	{
		for ( j = 0; j < cols2; j++)
			printf("%d\t",arr2[i][j]);

		printf("\n");
	}
	printf("\n");



while(1)
{
	printf("Please choose one of the following:\n1. Transpose\n2. Determinant\n3. Multiplication\nEnter your option:");
	scanf("%d",&option);

	while(getchar() != '\n');

/********************************************************************************************/
	//Transpose
	if( option == 1 )
	{
	int tarr1[cols1][rows1];
	
		//Perform Transpose operation
		for ( i = 0; i < rows1; i++)
			for ( j = 0; j < cols1; j++)
				tarr1[j][i] = arr1[i][j];

		printf("\nTranspose array is\n");
		for ( i = 0; i < rows1; i++)
		{
			for ( j = 0; j < cols1; j++)
				printf("%d\t",tarr1[i][j]);

			printf("\n");
		}
	}

/********************************************************************************************/

	//Determinant	
	if( option == 2 )
	{

		if( rows1 != cols1 || rows2 != cols2)
		{
			printf("Invalid number of rows and columns to perform determinant. Determinant can be calculated only for square matrix. Please quit and try again.\n");
			goto end;
		}

		//3X3 Matrix
		if( rows1 == 3 && cols1 == 3 )
		{
			printf("3X3\n");

			//Finding determinant
			for( i = 0; i < 1; i++ )
			{
				for( j = 0; j < 3; j++ )
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
					else if( j == 2 )
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
	
		//2X2 Matrix
		else if( rows1 == 2 && cols1 == 2 )
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
	}

/********************************************************************************************/

	//Multiplication
	else if( option == 3 )
	{

		if( cols1 != rows2 )
		{
			printf("Invalid number of rows and columns to perform multiplication.\n");
			goto end;
		}

		//Perform Multiplication operation
		for ( i = 0; i < rows1; i++)
		{
			for ( j = 0; j < cols2; j++)
			{
				for( k = 0; k < rows2; k++ )
				{
					sum += arr1[i][k]*arr2[k][j];

				}
				arr[i][j] = sum;
				sum = 0;
			}
		}

		printf("\nResult array is\n");
		for ( i = 0; i < rows1; i++)
		{
			for ( j = 0; j < cols2; j++)
				printf("%d\t",arr[i][j]);
				printf("\n");
		}
	}

	printf("\n");

end:	//Ask user for options
	printf("Do you want to continue(Y/N):");
	char ch=getchar();
	while(getchar() != '\n');
	if((ch == 'N' || ch == 'n'))
	{
		break;
	}
}

	return 0;
}
