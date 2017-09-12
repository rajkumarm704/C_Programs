#include<stdio.h>
int main()
{
	int percentage;
	printf("Enter Percentage: ");
	scanf("%d",&percentage);
	if(percentage>=90)
		printf("Grade is A.\n");
	else if(percentage>=80 && percentage<90)
		printf("Grade is B.\n");
	else if(percentage>=70 && percentage<80)
		printf("Grade is C.\n");
	else if(percentage>=60 && percentage<70)
		printf("Grade is D.\n");
	else if(percentage>=50 && percentage<60)
		printf("Grade is E.\n");
	if(percentage<50)
		printf("Student Failed.\n");
return 0;
}
