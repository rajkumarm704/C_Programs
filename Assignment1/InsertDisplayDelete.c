#include<stdio.h>
#include<stdlib.h>

void cne(void);
void ubound(void);
void lbound(void);

int check_space(int *option, int limit, int *inindx)
{
	int i, space_count = 0, flag = 0;
	for( i = 0; i < 8; i++ )
	{
		if ( option[i] == 0 )
		{
			space_count++;
			flag = 1;
		}
		else if ( flag == 1 )
			break;
	}

	if( space_count >= limit )
		*inindx = i - space_count;	

	return space_count;
}


void replace_data(int *arr, int src)
{
	int i;
	for( i = 0; i < 8; i++)
		if(arr[i] == src)
			arr[i] = 0;
}

void main()
{
	cne();
	ubound();

//Variables

//space_count:used to check whether there is appropriate space available for data
//Example:char, char, empty, empty, char, empty, empty, empty
//Here 4 bytes are avaiable but int cannot be inserted because continous memory is not available.
	int space_count = 0;

	void *mptr, *tptr, *data;
	char ch;
	int option1, option2, count = 0, count_t = 0, iter = 0, display_count = 1;

//result:it store the result whether space is available for a data to insert
	int result = 0;


	int option[8];

	mptr = malloc(8);
	tptr = mptr;

	int i, dindx = 0, inindx = 0;

	for ( i = 0; i < 8; i++ )
		option[i] = 0;
	i = 0;

	while(1)
	{


		//Display Operations Menu
		printf("Select an operation to perform:\n1. Insert\n2. Display\n3. Delete\nYour option:");
		//Take operation index
		scanf("%d",&option1);

		while(getchar() != '\n');

		//Insert Operation
		if ( option1 == 1 )
		{
			if( count < 8 )
			{
				printf("\n\nChoose the Data type to Insert\n1. Integer\n2. Character\n3. Float\n4. Double\nYour option:");
				scanf("%d",&option2);	

				while(getchar() != '\n');
			}	
//			else
//				printf("Space is full. You may delete some data to free up space.\n");
		}
		//Display Operation
		else if ( option1 == 2 )
		{
			printf("\n");
			for( i = 0; i < 8; i++)
			{
				if(option[i] == 1)
					printf("int, ");
				else if(option[i] == 2)
					printf("char, ");
				else if(option[i] == 3)
					printf("float, ");
				else if(option[i] == 4)
					printf("double, ");
				else if(option[i] == 0)
					printf("empty, ");
			}

			printf("\n\nActual Data\n\n");

			for( i = 0; i < 8; i++)
			{
				if(option[i] == 1)
				{
					printf("%d, ",*( (int *)( mptr ) + i ) );
					i += 3;
				}
				else if(option[i] == 2)
				{
					printf("%c, ",*( (char *)( mptr ) + i ) );
				}
				else if(option[i] == 3)
				{
					printf("%f, ",*( (float *)( mptr ) + i ) );
					i += 3;
				}
				else if(option[i] == 4)
				{
					printf("%lf, ",*( (double *)( mptr ) + i ) );
					i += 7;
				}
				else if(option[i] == 0)
					printf("empty, ");

			}
		}

		//Delete operation
		else if( option1 == 3 )
		{
			if( count > 0 )
			{
				printf("\ndelete operation\n");

				printf("\n\nChoose the Data type to Delete\n1. Integer\n2. Character\n3. Float\n4. Double\nYour option:");
				scanf("%d",&option2);
			}
			else
				printf("There is no data to delete. You may use Insert operation to insert data.\n");
		}	


		//Performing Insert operation
		if( option1 == 1)
		{
			if(inindx > 8 )
				inindx = 0;	

			if( option2 == 1)
			{
				result = check_space( option, 4, &inindx );
//				printf("Result:%d\n",result);

				count_t += sizeof(int);
				if ( count_t > 8 )
				{
					printf("Integer Space is full. You may delete some data to free up space.\n");
					count = count;
					count_t -= sizeof(int);
				}
				else if( count_t <= 8 && count_t >= 0 && result >= 4 )
				{
					//Insert data
					printf("Enter the data:");
					scanf("%d", (int *)data );
					*( (int *)( mptr ) + inindx ) = *(int *)data;

					while(getchar() != '\n');

					count = count_t;
					while(iter != 4)
					{
						option[inindx] = 1;
						iter++;
						inindx++;
					}
					iter = 0;
				}
			}
			else if( option2 == 2)
			{
				result = check_space( option, 1, &inindx );
				count_t += sizeof(char);

				if ( count_t > 8 )
				{
					printf("Character Space is full. You may delete some data to free up space.\n");
					count = count;
					count_t -= sizeof(char);
				}
				else if( count_t <= 8 && count_t >= 0 && result >= 1 )
				{
					//Insert data
					printf("Enter the data:");
					scanf("%c", (char *)data );
					*( (char *)( mptr ) + inindx ) = *(char *)data;

					while(getchar() != '\n');

					count = count_t;
					while(iter != 1)
					{
						option[inindx] = 2;
						iter++;
						inindx++;
					}
					iter = 0;
				}
			}
			else if( option2 == 3)
			{

				result = check_space( option, 4, &inindx );
				count_t += sizeof(float);

				if ( count_t > 8 )
				{
					printf("Float Space is full. You may delete some data to free up space.\n");
					count = count;
					count_t -= sizeof(float);
				}
				else if( count_t <= 8 && count_t >= 0 && result >= 4 )
				{
					//Insert data
					printf("Enter the data:");
					scanf("%f", (float *)data );
					*( (float *)( mptr ) + inindx ) = *(float *)data;

					while(getchar() != '\n');

					count = count_t;
					while(iter != 4)
					{
						option[inindx] = 3;
						iter++;
						inindx++;
					}
					iter = 0;

				}
			}
			else if( option2 == 4)
			{
				result = check_space( option, 8, &inindx );
				count_t += sizeof(double);

				if ( count_t > 8 )
				{
					printf("Double Space is full. You may delete some data to free up space.\n");
					count = count;
					count_t -= sizeof(double);
				}
				else if( count_t <= 8 && count_t >= 0 && result >= 8 )
				{
					//Insert data
					printf("Enter the data:");
					scanf("%lf", (double *)data );
					*( (double *)( mptr ) + inindx ) = *(double *)data;

					while(getchar() != '\n');

					count = count_t;
					while(iter != 8)
					{
						option[inindx] = 4;
						iter++;
						inindx++;
					}
					iter = 0;
				}

			}
		}


		//Performing Delete operation
		if( option1 == 3)
		{
			if( option2 == 1)
			{
				count_t -= sizeof(int);
				
				if ( count_t > 8 || count_t < 0 )
				{
					count = count;
					count_t += sizeof(int);
				}
				else
				{
					count = count_t;
					replace_data(option, 1);
				}
			}
			else if( option2 == 2)
			{
				count_t -= sizeof(char);
				if ( count_t > 8 || count_t < 0 )
				{
					count = count;
					count_t += sizeof(char);
				}
				else
				{
					count = count_t;
					replace_data(option, 2);
				}

			}
			else if( option2 == 3)
			{
				count_t -= sizeof(float);
				if ( count_t > 8 || count_t < 0 )
				{
					count = count;
					count_t += sizeof(float);
				}
				else
				{
					count = count_t;
					replace_data(option, 3);
				}

			}
			else if( option2 == 4)
			{
				count_t -= sizeof(double);
				if ( count_t > 8 || count_t < 0 )
				{
					count = count;
					count_t += sizeof(double);
				}
				else
				{
					count = count_t;
					replace_data(option, 4);
				}

			}
			dindx++;
		}

		if( count_t > 8 )
			printf("Memory Full. \n");

		lbound();

		//Ask user for options
		printf("Do you want to continue(Y/N):");
		char ch=getchar();
		while(getchar() != '\n');
		if((ch == 'N' || ch == 'n'))
		{
			break;
		}

	}

	free(mptr);
	free(data);


}



void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc InsertDisplayDelete.c -o InsertDisplayDelete.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}
