#include<stdio.h>
int main()
{

//Declarations
int a,b,play_count,rnum,i,j,sum,count=0;
char ch;
srand(6);

//Infinite loop
while(1)
{

//Prompt user for input
printf("Enter the number of plays: ");
scanf("%d",&play_count);

//Create arrays based on user input
int player1[play_count],player2[play_count];

//Clear buffer
while(getchar()!='\n');

//Genrate player 1 outcomes
	for(i=0;i<play_count;i++)
	{
		a=rand()%6;
		a=(a==0)?6:a;
		b=rand()%6;
		b=(b==0)?6:b;
		sum=a+b;
		player1[i]=sum;
		printf("Player 1 Outcome number %d are %d,%d \n", i+1,a,b);

	}
	printf("**********************************\n");

//Genrate player 2 outcomes
	for(i=0;i<play_count;i++)
	{
		a=rand()%6;
		a=(a==0)?6:a;
		b=rand()%6;
		b=(b==0)?6:b;
		sum=a+b;
		player2[i]=sum;
		printf("Player 2 Outcome number %d are %d,%d \n", i+1,a,b);

	}

//Print sum array of player 1
	printf("\nPlayer 1 outcome sum array:\t");
	for(i=0;i<play_count;i++)
		printf("%d\t ",player1[i]);

	printf("\n");

//Print sum array of player 2
	printf("\nPlayer 2 outcome sum array:\t");
	for(i=0;i<play_count;i++)
		printf("%d\t ",player2[i]);

	printf("\n");

//Check for players arrays for common sums
	for(i=0;i<play_count;i++)
	{
		for(j=0;j<play_count;j++)
		{
			if(player1[i]==player2[j])
				count++;
		}
	}

//Display message accordingly
	if(count==play_count)
		printf("\nThe players are lucky...\n");
	else
		printf("\nThe players are unlucky :(\n");


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
