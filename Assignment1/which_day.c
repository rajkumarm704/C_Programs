#include<stdio.h>
int main()
{
	//Declarations
	int year,day,leap_year;
	int start_day;


while(1)
{
	//Prompt user for input
	printf("Enter the year: ");
	scanf("%d",&year);

	//Clear Buffer
	while(getchar() != '\n');

	printf("Enter the first day of year\n1:mon\n2:tue\n3:wed\n4:thu\n5:fri\n6:sat\n7:sun\n");
	scanf("%d",&start_day);

	//Clear Buffer
	while(getchar() != '\n');


	if(start_day>7||start_day<1)
	{
		printf("Ivalid option. Try again.\n");
		goto end;
	}

	printf("Enter the day of year: ");
	scanf("%d",&day);

	//Clear Buffer
//	while(getchar() != '\n');

	//Find Out if its leap year
	leap_year=year%4;
	
	//Display error in case of invalid input
	if(leap_year == 0 && day>365 )
	{
		printf("Its a leap year. Please enter a value less than 365.\n");
		goto end;
	}
	else if(day>365 )
	{
		printf("Please enter a value less than 365.\n");
		goto end;
	}

	//Clear Buffer
	while(getchar() != '\n');

	int rem_day=day%7;
	int exact_day;
	
	//Calculate day of the week
	exact_day=start_day+rem_day-1;

	if(exact_day>7)
		exact_day=exact_day-7;

	//Display result according to options
	if(exact_day==1)
		printf("Monday\n");
	else if(exact_day==2)
		printf("Tueday\n");
	else if(exact_day==3)
		printf("Wednesday\n");
	else if(exact_day==4)
		printf("Thursday\n");
	else if(exact_day==5)
		printf("Friday\n");
	else if(exact_day==6)
		printf("Saturday\n");
 	else if(exact_day==7)
		printf("Sunday\n");

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

