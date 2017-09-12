#include<stdio.h>
int main()
{

//Declarations
int num,i;
char ch;
int temp,temp_copy,num_count,j,prime_count;

while(1)
{
	prime_count=0;

//Prompt user for input
	printf("Enter the number: ");
	scanf("%d",&num);

//Clear buffer
	while(getchar() != '\n');

//Create arrays with size provided by the user
	int arr[num],num_arr[num],prime_arr[num];

//Store the numbers in array
	for(i=0;i<num;i++)
	{
		arr[i]=1;
		num_arr[i]=i;
	}

//Findout prime numbers from array
	for(i=0;i<num;i++)
	{
		for(j=1;j<=i;j++)
		{
			temp=i%j;
			if(temp==0)
				prime_count++;
		}

		prime_arr[i]=prime_count==2?1:0;
		prime_count=0;
	}

	prime_arr[1]=1;
	printf("Prime numbers are:");

//Display prime numbers
	for(i=0;i<num;i++)
	{
		if(prime_arr[i]==1)
			printf("%d,  ",i);
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

