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
			printf("CASE I\n");
			if(m!=n)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			printf("Both odd.\n");

			//Finding out middle number of m & n
			id_x=(m+1)/2;
			id_y=(n+1)/2;

//			printf("before for loop:%d,%d\n",id_x,id_y);
//			printf("entering value:%d@%d,%d\n",value,id_x,id_y);
			arr[id_x-1][id_y-1]=value;
			++value;

			for(i=1;i<=m;i++)
			{
//				printf("\n\ni:%d\n",i);

				//When i is odd
				if(i%2 != 0)
				{
					for(a=0;a<i-1;a++)
					{
						id_x=id_x-1;
						arr[id_x-1][id_y-1]=value;
						++value;	
//						printf("a:%d,value:%d@%d,%d\t",a,value,id_x,id_y);
					}	

//					printf("*\t");
					for(b=1;b<=i;b++)
					{
						id_y=id_y-1;
						arr[id_x-1][id_y-1]=value;
						++value;
//						printf("b:%d,value:%d@%d,%d\t",b,value,id_x,id_y);
					}	
		
//					printf("\n");
				}

				//When i is even
				else if(i%2 == 0)
				{
					for(a=0;a<i-1;a++)
					{
						id_x=id_x+1;
						arr[id_x-1][id_y-1]=value;
						++value;
//						printf("a:%d,value:%d@%d,%d\t",a,value,id_x,id_y);
					}	

//					printf("*\t");
					for(b=1;b<=i;b++)
					{
						id_y=id_y+1;
						arr[id_x-1][id_y-1]=value;
						++value;
//						printf("b:%d,value:%d@%d,%d\t",b,value,id_x,id_y);
					}	
		
//					printf("\n");
				}

			}

			printf("\n*************************\n");

		//Display array values
		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				printf("%d\t",arr[a][b]);
			}
			printf("\n");
		}


		}			
	/******************END FIRST CASE**********************/

	/******************SECOND CASE**********************/

	//For m=even & n=even
		else if(m_type == 0 && n_type == 0)
		{
			printf("CASE II\n");
			if(m!=n)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			printf("\nBoth even.\n");

	//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n)/2;
	//		printf("before for loop:%d,%d\n",id_x,id_y);
	//		printf("entering value:%d@%d,%d\n",value,id_x,id_y);
			arr[id_x][id_y-1]=value;
			++value;

		for(i=1;i<=m;i++)
		{
	//		printf("\n\ni:%d\n",i);

	//When i is odd
			if(i%2 != 0)
			{
				for(a=0;a<i-1;a++)
				{
					id_x=id_x+1;
					arr[id_x][id_y-1]=value;
					++value;
	//				printf("a:%d,value:%d@%d,%d\t",a,value,id_x,id_y);
				}	

	//			printf("*\t");
				for(b=1;b<=i;b++)
				{
					id_y=id_y+1;
					arr[id_x][id_y-1]=value;
					++value;
	//				printf("b:%d,value:%d@%d,%d\t",b,value,id_x,id_y);
			}	
		
	//			printf("\n");
			}

	//When i is even
			else if(i%2 == 0)
			{
				for(a=0;a<i-1;a++)
				{
					id_x=id_x-1;
					arr[id_x][id_y-1]=value;
					++value;
	//				printf("a:%d,value:%d@%d,%d\t",a,value,id_x,id_y);
				}	

	//			printf("*\t");
				for(b=1;b<=i;b++)
				{
					id_y=id_y-1;
					arr[id_x][id_y-1]=value;
					++value;
	//				printf("b:%d,value:%d@%d,%d\t",b,value,id_x,id_y);
				}	
		
	//			printf("\n");
			}
		}

		printf("\n*************************\n");

		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				printf("%d\t",arr[a][b]);
			}
			printf("\n");
		}
		}			

	/******************END SECOND CASE**********************/

	/******************THIRD CASE**********************/

	//For m=odd & n=even
		else if(m_type != 0 && n_type == 0 && m>n)
		{
			printf("CASE III\n");	
		
			if(m-n>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			printf("\nm is odd & n is even.\n");
	//Finding out middle number of m & n
			id_x=(m+1)/2;
			id_y=(n)/2;
	//		printf("Starting point:%d,%d\n\n",id_x,id_y);
	//		printf("entering value:%d@%d,%d\n",value,id_x-1,id_y-1);
			arr[id_x-1][id_y-1]=value;
			++value;

		for(i=1;i<=m;i++)
		{
	//		printf("\ni:%d\n",i);

	//When i is odd
			if(i%2 != 0)
			{
				for(a=1;a<=i;a++)
				{
					id_x=id_x+1;
					if(value>m*n)
						continue;
					arr[id_x-1][id_y-1]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x-1,id_y-1);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{
					id_y=id_y+1;
					if(value>m*n)
						continue;
					arr[id_x-1][id_y-1]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x-1,id_y-1);
					++value;
				}	
		
	//			printf("\n");
			}

	//When i is even
			else if(i%2 == 0)
			{
				for(a=1;a<=i;a++)
				{
					id_x=id_x-1;
					if(value>m*n)
						continue;
					arr[id_x-1][id_y-1]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x-1,id_y-1);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{
					id_y=id_y-1;
					if(value>m*n)
						continue;
					arr[id_x-1][id_y-1]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x-1,id_y-1);
					++value;
				}	
		
	//			printf("\n");
			}
		}

		printf("\n*************************\n");

		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				printf("%d\t",arr[a][b]);
			}
			printf("\n");
		}
		}			

	/******************END THIRD CASE**********************/

	/******************FOURTH CASE**********************/

	//For m=even & n=odd m<n
		else if(m_type == 0 && n_type != 0 && n>m)
		{
			printf("CASE IV\n");
		
			if(n-m>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			printf("\nm is even & n is odd. m<n.\n");
	//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n+1)/2;
			--id_x;
			--id_y;
			id_x++;
			id_y--;
	//		printf("Starting point:%d,%d\n\n",id_x,id_y);
	//		printf("entering value:%d@%d,%d\n",value,id_x,id_y);
			arr[id_x][id_y]=value;
			++value;

		for(i=1;i<=m;i++)
		{
	//		printf("\ni:%d\n",i);

	//When i is odd
			if(i%2 != 0)
			{
				for(a=1;a<=i+1;a++)
				{
					//printf("+%d,",a);
					id_y=id_y+1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x,id_y);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{
					//printf("-%d,",b);
					id_x=id_x-1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x,id_y);
					++value;
				}			
	//			printf("\n");
			}

	//When i is even
			else if(i%2 == 0)
		{
				for(a=1;a<=i+1;a++)
				{
					//printf("-%d,",a);
					id_y=id_y-1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x,id_y);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{	
					//printf("+%d,",b);
					id_x=id_x+1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x,id_y);
					++value;
				}	
		
	//			printf("\n");
			}
		}
		printf("\n*************************\n");
		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				printf("%d\t",arr[a][b]);
			}
			printf("\n");
		}
		}			

	/******************END FOURTH CASE**********************/


	/******************FIFTH CASE**********************/

	//For m=even & n=odd m>n
		else if(m_type == 0 && n_type != 0 && m>n)
		{
			printf("CASE V\n");
			if(m-n>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			printf("\nm is even & n is odd. m>n.\n");
	//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n+1)/2;
			--id_x;
			--id_y;
			id_x++;
	//		printf("Starting point:%d,%d\n\n",id_x,id_y);
	//		printf("entering value:%d@%d,%d\n",value,id_x,id_y);
			arr[id_x][id_y]=value;
			++value;

		for(i=1;i<=m;i++)
		{
	//		printf("\ni:%d\n",i);

	//When i is odd
			if(i%2 != 0)
			{
				for(a=1;a<=i;a++)
				{
					//printf("+%d,",a);
					id_x=id_x-1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x,id_y);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{
					//printf("-%d,",b);
					id_y=id_y-1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x,id_y);
					++value;
				}			
	//			printf("\n");
			}

	//When i is even
			else if(i%2 == 0)
		{
				for(a=1;a<=i;a++)
				{
					//printf("-%d,",a);
					id_x=id_x+1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x,id_y);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{	
					//printf("+%d,",b);
					id_y=id_y+1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x,id_y);
					++value;
				}	
		
	//			printf("\n");
			}
		}

		printf("\n*************************\n");

		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				printf("%d\t",arr[a][b]);
			}
			printf("\n");
		}
		}			

	/******************END FIFTH CASE**********************/

	/******************SIX CASE**********************/

	//For m=even & n=odd m<n
		else if(m_type != 0 && n_type == 0 && n>m)
		{
			printf("CASE VI\n");		
			if(n-m>1)
			{
				printf("Difference between m & n should be 1.Please try again...\n");
				goto end;
			}

			printf("\nm is even & n is odd. m<n.\n");
	//Finding out middle number of m & n
			id_x=(m)/2;
			id_y=(n+1)/2;
			--id_x;
			--id_y;
			id_x++;
			id_y++;
	//		printf("Starting point:%d,%d\n\n",id_x,id_y);
	//		printf("entering value:%d@%d,%d\n",value,id_x,id_y);
			arr[id_x][id_y]=value;
			++value;

		for(i=1;i<=m;i++)
		{
	//		printf("\ni:%d\n",i);

	//When i is odd
			if(i%2 != 0)
			{
				for(a=1;a<=i+1;a++)
				{
					//printf("+%d,",a);
					id_y=id_y-1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x,id_y);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{
					//printf("-%d,",b);
					id_x=id_x+1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x,id_y);
					++value;
				}			
	//			printf("\n");
			}

	//When i is even
			else if(i%2 == 0)
		{
				for(a=1;a<=i+1;a++)
				{
					//printf("-%d,",a);
					id_y=id_y+1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("a:%d,value:%d@%d,%d|",a,value,id_x,id_y);
					++value;
				}	

	//			printf("\n");
				for(b=1;b<=i;b++)
				{	
					//printf("+%d,",b);
					id_x=id_x-1;
					if(value>m*n)
						continue;
					arr[id_x][id_y]=value;
	//				printf("b:%d,value:%d@%d,%d|",b,value,id_x,id_y);
					++value;
				}	
		
	//			printf("\n");
			}
		}
		printf("\n*************************\n");
		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				printf("%d\t",arr[a][b]);
			}
			printf("\n");
		}
		}			

	/******************END SIX CASE**********************/


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
