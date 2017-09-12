#include<stdio.h>
#include<stdlib.h>

void cne();
void ubound();
void lbound();



int main()
{

	cne();
	ubound();

	int dtype, n, i;
	int j, count = 0;
//	int j, t, t1, count = 0;
	void *t, *t1, *t2;
	void *mptr;

	printf("Choose a Data type\n1. Integer\n2. Character\n3. Float\n4. String\nYour option:");
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
			t = malloc(sizeof(int));
			t1 = malloc(sizeof(int));
			t2 = malloc(sizeof(int));

			//Take user input
			for ( i = 0; i < n ; i++ )
			{
				scanf("%d",( (int *)( mptr ) + i) );
			}

			//Perform sorting mechanism
			for ( i = 0; i < n; i++ )
			{
				*(int *)t = *( (int *)( mptr ) + i );

				for( j = i; j < n ; j++ )
				{
					*(int *)t1 = *( (int *)( mptr ) + j );

					if(  *(int *)t1  < *(int *)t )
					{
						count = j;
						*(int *)t = *( (int *)( mptr ) + j );
					}
				}

				if( count != 0 )
				{
					*(int *)t2 = *( (int *)( mptr ) + i );
					*( (int *)( mptr ) + i ) = *( (int *)( mptr ) + count );
					*( (int *)( mptr ) + count ) = *(int *)t2 ;
				}

				count = 0;
			}

			printf("Sorted array is:");
			for ( i = 0; i < n; i++ )
				printf("%d, ",*( (int *)( mptr ) + i ) );	
			printf("\n");


			printf("Enter an element to search:");
			scanf("%d",(int *)t);

			for( i = 0; i < n; i++ )
			{
				if( *(int *)t == *( (int *)( mptr ) + i ) )
				{
					j = 1;
					break;
				}
				else
					j = 0;
			}

			if( j == 1 )
				printf("Element found...\n");
			else if ( j == 0 )
				printf("Element not found. Please try again.\n");


			break;
/*******************************************************************************************/


		case 2:
			//Allocate memory for data storing
			mptr = malloc(n*sizeof(char));
			t = malloc(sizeof(char));
			t1 = malloc(sizeof(char));
			t2 = malloc(sizeof(char));

			while(getchar() != '\n');

			//Take user input
			for ( i = 0; i < n ; i++ )
			{
				scanf("%c",( (char *)( mptr ) + i) );
				while(getchar() != '\n');
			}

			//Perform sorting mechanism
			for ( i = 0; i < n; i++ )
			{
				*(char *)t = *( (char *)( mptr ) + i );

				for( j = i; j < n ; j++ )
				{
					*(char *)t1 = *( (char *)( mptr ) + j );

					if(  *(char *)t1  < *(char *)t )
					{
						count = j;
						*(char *)t = *( (char *)( mptr ) + j );
					}
				}

				if( count != 0 )
				{
					*(char *)t2 = *( (char *)( mptr ) + i );
					*( (char *)( mptr ) + i ) = *( (char *)( mptr ) + count );
					*( (char *)( mptr ) + count ) = *(char *)t2 ;
				}

				count = 0;
			}

			printf("Sorted array is:");
			for ( i = 0; i < n; i++ )
				printf("%c, ",*( (char *)( mptr ) + i ) );	
			printf("\n");

			//Search element
			printf("Enter an element to search:");
			scanf("%c",(char *)t);

			while(getchar() != '\n');

			for( i = 0; i < n; i++ )
			{
				if( *(char *)t == *( (char *)( mptr ) + i ) )
				{
					j = 1;
					break;
				}
				else
					j = 0;
			}

			if( j == 1 )
				printf("Element found...\n");
			else if ( j == 0 )
				printf("Element not found. Please try again.\n");


			break;
/*******************************************************************************************/

		case 3:
			//Allocate memory for data storing
			mptr = malloc(n*sizeof(float));
			t = malloc(sizeof(float));
			t1 = malloc(sizeof(float));
			t2 = malloc(sizeof(float));

			//Take user input
			for ( i = 0; i < n ; i++ )
				scanf("%f",( (float *)( mptr ) + i) );

			//Perform sorting mechanism
			for ( i = 0; i < n; i++ )
			{
				*(float *)t = *( (float *)( mptr ) + i );

				for( j = i; j < n ; j++ )
				{
					*(float *)t1 = *( (float *)( mptr ) + j );

					if(  *(float *)t1  < *(float *)t )
					{
						count = j;
						*(float *)t = *( (float *)( mptr ) + j );
					}
				}

				if( count != 0 )
				{
					*(float *)t2 = *( (float *)( mptr ) + i );
				*( (float *)( mptr ) + i ) = *( (float *)( mptr ) + count );
					*( (float *)( mptr ) + count ) = *(float *)t2 ;
				}

				count = 0;
			}

			printf("Sorted array is:");
			for ( i = 0; i < n; i++ )
				printf("%.1f, ",*( (float *)( mptr ) + i ) );	
			printf("\n");

			//Search element
			printf("Enter an element to search:");
			scanf("%f",(float *)t);

			for( i = 0; i < n; i++ )
			{
				if( *(float *)t == *( (float *)( mptr ) + i ) )
				{
					j = 1;
					break;
				}
				else
					j = 0;
			}

			if( j == 1 )
				printf("Element found...\n");
			else if ( j == 0 )
				printf("Element not found. Please try again.\n");

			break;
/*******************************************************************************************/

		case 4:
			//Allocate memory for data storing
			mptr = malloc(20*sizeof(char));

			//Take user input
			scanf("%s", (char *)( mptr ) );

			break;

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
	system("gcc generic_sort_search.c -o generic_sort_search.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}

