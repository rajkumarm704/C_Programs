#include<stdio.h>
int main()
{

	//Declare variables
	int num,m,n,i,a,b,id_x=0,id_y=0;
	char ch;
	int m_type=0,n_type=0;
	int value;

	//Infinte loop
	while(1)
	{
		value=1;
		
		//Prompt user for input
		printf("Enter the value of m & n: ");
		scanf("%d %d",&m,&n);
	
		//Clear the buffer
		while(getchar() != '\n');

		//Declare a 2D array
		int arr[m][n];

		//Initialising 2D array with 0 values
		for(a=0;a<m;a++)
			for(b=0;b<n;b++)
				arr[a][b]=0;

		//Finding out if m & n are even or odd
		m_type=m%2;
		n_type=n%2;

/******************FIRST CASE**********************/

		//For m=odd & n=odd
		if(m_type != 0 && n_type != 0)
		{
			if(m!=n)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			//Finding out middle number of m & n
			id_x=(m+1)/2;
			id_y=(n+1)/2;

			//Enter the starting value at center of matrix
			arr[id_x-1][id_y-1]=value;

			//Increment the value
			++value;

			//Pattern:(-0;-1|+1;+1,+2|-1,-2;-1,-2,-3|+1,+2,+3;+1,+2,+3,+4)
			//odd  i ==>'-'
			//even i ==>'+'
			for(i=1;i<=m;i++)
			{
				//When i is odd
				if(i%2 != 0)
				{
					//Genrate numbers according to pattern
					for(a=0;a<i-1;a++)
					{
						id_x=id_x-1;
						arr[id_x-1][id_y-1]=value;
						++value;	
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_y=id_y-1;
						arr[id_x-1][id_y-1]=value;
						++value;
					}	
				}

				//When i is even
				else if(i%2 == 0)
				{
					//Genrate numbers according to pattern
					for(a=0;a<i-1;a++)
					{
						id_x=id_x+1;
						arr[id_x-1][id_y-1]=value;
						++value;
					}	
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_y=id_y+1;
						arr[id_x-1][id_y-1]=value;
						++value;
					}	
				}
			}
		}			
/******************END FIRST CASE**********************/

/******************SECOND CASE**********************/

		//For m=even & n=even
		else if(m_type == 0 && n_type == 0)
		{
			if(m!=n)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n)/2;

			//Enter the starting value at center of matrix			
			arr[id_x][id_y-1]=value;

			//Increment the value
			++value;
			for(i=1;i<=m;i++)
			{
				//When i is odd
				if(i%2 != 0)
				{
					//Genrate numbers according to pattern
					for(a=0;a<i-1;a++)
					{
						id_x=id_x+1;
						arr[id_x][id_y-1]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_y=id_y+1;
						arr[id_x][id_y-1]=value;
						++value;
					}	
				}

				//When i is even
				else if(i%2 == 0)
				{
					//Genrate numbers according to pattern
					for(a=0;a<i-1;a++)
					{
						id_x=id_x-1;
						arr[id_x][id_y-1]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_y=id_y-1;
						arr[id_x][id_y-1]=value;
						++value;
					}	
				}
			}
		}			

/******************END SECOND CASE**********************/

/*********************THIRD CASE************************/

		//For m=odd & n=even
		else if(m_type != 0 && n_type == 0 && m>n)
		{		
			if(m-n>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}
			
			//Finding out middle number of m & n
			id_x=(m+1)/2;
			id_y=(n)/2;

			//Enter the starting value at center of matrix
			arr[id_x-1][id_y-1]=value;

			//Increment the value
			++value;
			for(i=1;i<=m;i++)
			{
				//When i is odd
				if(i%2 != 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i;a++)
					{
						id_x=id_x+1;
						if(value>m*n)
							continue;
						arr[id_x-1][id_y-1]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_y=id_y+1;
						if(value>m*n)
							continue;
						arr[id_x-1][id_y-1]=value;
						++value;
					}	
				}

				//When i is even
				else if(i%2 == 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i;a++)
					{
						id_x=id_x-1;
						if(value>m*n)
							continue;
						arr[id_x-1][id_y-1]=value;
						++value;
					}
					//Genrate numbers according to pattern	
					for(b=1;b<=i;b++)
					{
						id_y=id_y-1;
						if(value>m*n)
							continue;
						arr[id_x-1][id_y-1]=value;
						++value;
					}	
				}
			}
		}			

/******************END THIRD CASE**********************/

/********************FOURTH CASE**********************/

		//For m=even & n=odd m<n
		else if(m_type == 0 && n_type != 0 && n>m)
		{		
			if(n-m>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n+1)/2;
			--id_x;
			--id_y;
			id_x++;
			id_y--;

			//Enter the starting value at center of matrix
			arr[id_x][id_y]=value;

			//Increment the value
			++value;

			for(i=1;i<=m;i++)
			{	
				//When i is odd
				if(i%2 != 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i+1;a++)
					{
						id_y=id_y+1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_x=id_x-1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}			
				}

				//When i is even
				else if(i%2 == 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i+1;a++)
					{
						id_y=id_y-1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{	
						id_x=id_x+1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}	
				}
			}
		}			

/******************END FOURTH CASE**********************/

/********************FIFTH CASE*************************/

		//For m=even & n=odd m>n
		else if(m_type == 0 && n_type != 0 && m>n)
		{
			if(m-n>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n+1)/2;
			--id_x;
			--id_y;
			id_x++;

			//Enter the starting value at center of matrix
			arr[id_x][id_y]=value;

			//Increment the value
			++value;

			for(i=1;i<=m;i++)
			{
				//When i is odd
				if(i%2 != 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i;a++)
					{
						id_x=id_x-1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_y=id_y-1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}			
				}

				//When i is even
				else if(i%2 == 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i;a++)
					{
						id_x=id_x+1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}
					//Genrate numbers according to pattern	
					for(b=1;b<=i;b++)
					{	
						id_y=id_y+1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}	
		
				}
			}
		}			

/******************END FIFTH CASE**********************/

/******************SIX CASE**********************/

		//For m=even & n=odd m<n
		else if(m_type != 0 && n_type == 0 && n>m)
		{	
			if(n-m>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}
		
			//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n+1)/2;
			--id_x;
			--id_y;
			id_x++;
			id_y++;

			//Enter the starting value at center of matrix
			arr[id_x][id_y]=value;

			//Increment the value
			++value;

			for(i=1;i<=m;i++)
			{
				//When i is odd
				if(i%2 != 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i+1;a++)
					{
						id_y=id_y-1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{
						id_x=id_x+1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}			
				}

				//When i is even
				else if(i%2 == 0)
				{
					//Genrate numbers according to pattern
					for(a=1;a<=i+1;a++)
					{
						id_y=id_y+1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}
					//Genrate numbers according to pattern
					for(b=1;b<=i;b++)
					{	
						id_x=id_x-1;
						if(value>m*n)
							continue;
						arr[id_x][id_y]=value;
						++value;
					}	
				}
			}

		}			

/******************END SIX CASE**********************/

		//Display values of array;
		printf("\n*************************\n\n");
		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				printf("%d\t",arr[a][b]);
			}
			printf("\n");
		}

	end:	//Ask user for options
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
