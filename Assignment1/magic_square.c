#include<stdio.h>

int num,num_copy;

//Up Movement Function
int up(int ii)
{
	//Decrement index and compare if it is less than least row value; if true assign it the maximum row value
	if(--ii<0)
		ii=num_copy-1;

	return ii;
}

//Right Movement Function
int right(int jj)
{
	//Increment index and check if it is greater than maximum column value;if tru assign it least column value
	if((++jj)>num_copy-1)
		jj=0;

	return jj;
}

//Main Function
int main()
{

int sq_num,i,j,result,ii,jj,ii_t,jj_t;
char ch;

while(1)
{
	//Prompt user for input
	printf("Enter the number:");
	scanf("%d",&num);

	//Clear buffer
	while(getchar() != '\n');

	//Make a copy of user input
	num_copy=num;

	//Declare a 2D array
	int arr[num][num];

	//Initialise 2D array with 0
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			arr[i][j]=0;

	//The first number to enter into array
	result=1;

	//Starting index value
	ii=0;
	jj=1;

	//Enter value in array
	arr[ii][jj]=result;

	//For loop to enter rest of the values in array
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			//Make a copy of array index
			ii_t=ii;
			jj_t=jj;
	
			//Increment the result
			result++;

			//Call up & right Function simultaneously
			ii=up(ii);
			jj=right(jj);
		
			//Check if value at this index is 0;if true enter the value
			if(arr[ii][jj]==0)
				arr[ii][jj]=result;
			else
			{
				//Get the last value of index from temporary variables
				ii=ii_t;
				jj=jj_t;
			
				//Call up & up Function simultaneously
				ii=up(ii);
				ii=up(ii);
	
				//Check if value at this index is 0;if true enter the value
				if(arr[ii][jj]==0)
					arr[ii][jj]=result;
			}
		}
	}

	printf("\n");

	//Display the value in 2D array
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
			printf("%d\t",arr[i][j]);

		printf("\n");
	}

	//Ask user for options
	printf("\nDo you want to continue(Y/N):");
	ch=getchar();
	while(getchar() != '\n');
	if(!(ch == 'Y' || ch == 'y'))
	{
		break;
	}

}
return 0;
}
