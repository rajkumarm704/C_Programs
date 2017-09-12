#include<stdio.h>
#include<stdlib.h>

void cne();
void ubound();
void lbound();



int main()
{

	cne();
	ubound();

	int dtype, n, i, j;
	float sum = 0;
	void *mptr;

	printf("Choose a Data type\n1. Integer\n2. Character\n3. Float\nYour option:");
	scanf("%d",&dtype);

	printf("Enter the number of elements:");
	scanf("%d",&n);

	printf("Enter elements:");

	switch(dtype)
	{
/*******************************************************************************************/
		case 1:
			//Allocate memory for data storing
			mptr = malloc(n*sizeof(int));

			//Take user input
			for ( i = 0; i < n ; i++ )
			{
				scanf("%d",( (int *)( mptr ) + i) );
				sum += *( (int *)( mptr ) + i );
			}

			sum /= i ;

			printf("The mean is: %f\n", sum );
			sum = 0;
			break;
/*******************************************************************************************/


		case 2:
			//Allocate memory for data storing
			mptr = malloc(n*sizeof(char));

			while(getchar() != '\n');

			//Take user input
			for ( i = 0; i < n ; i++ )
			{
				scanf("%c",( (char *)( mptr ) + i) );
				while(getchar() != '\n');
				sum += (float)*( (char *)( mptr ) + i );
			}

			sum /= i ;

			printf("The mean is: %c(value:%f, %d)\n", (char)sum, sum, (int)sum );
			sum = 0;
			break;

/*******************************************************************************************/

		case 3:
			//Allocate memory for data storing
			mptr = malloc(n*sizeof(float));

			//Take user input
			for ( i = 0; i < n ; i++ )
			{
				scanf("%f",( (float *)( mptr ) + i) );
				sum += *( (float *)( mptr ) + i );
			}

			sum /= i ;

			printf("The mean is: %f\n", sum );
			sum = 0;
			break;
/*******************************************************************************************/

		default: 
			printf("You have entered wrong option. Please try again...\n");

	}




	lbound();

	return 0;
}


void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc generic_mean.c -o generic_mean.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}

