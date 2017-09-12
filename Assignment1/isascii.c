#include<stdio.h>

int response;

//Function Declarations
int isalnum_f(char c)
{
	if(c>47 && c <58 || c>64 && c <91 || c>96 && c <123 )
		response=1;
	else
		response=0;
	printf("%d\n",response);
	return response;
}

int isalpha_f(char c)
{
	if(c>=65 && c <=90 || c>=97 && c <=122 )
		response=1;
	else
		response=0;

	return response;
}



int isascii_f(char c)
{
	if(c>=0 && c <=127 )
		response=1;
	else
		response=0;

	return response;
}


int isblank_f(char c)
{
	if(c==9 || c ==11 || c==32 )
		response=1;
	else
		response=0;

	return response;
}



int iscntrl_f(char c)
{
	printf("Nothing to display.");
}


int isdigit_f(char c)
{
	if(c>=48 && c <=57 )
		response=1;
	else
		response=0;

	return response;
}



int isgraph_f(char c)
{
	if(c>=33 && c <=126 )
		response=1;
	else
		response=0;

	return response;
}



int islower_f(char c)
{
	if(c>=97 && c <=122 )
		response=1;
	else
		response=0;

	return response;
}



int isprint_f(char c)
{
	if(c>=32 && c <=126 )
		response=1;
	else
		response=0;

	return response;
}



int ispunct_f(char c)
{
	if(c>=41 && c <=47 || c>=58 && c <=64 || c>=91 && c <=96 || c>=123 && c <=126)
		response=1;
	else
		response=0;

	return response;
}



int isspace_f(char c)
{
	if(c==32)
		response=1;
	else
		response=0;

	return response;
}



int isupper_f(char c)
{
	if(c>=65 && c <=90 )
		response=1;
	else
		response=0;

	return response;
}



int isxdigit_f(char c)
{
	if(c>=48 && c <=57 || c>=65 && c <=70 || c>=97 && c <=102 )
		response=1;
	else
		response=0;

	return response;
}


//Main function
int main()
{

//Declarations
char c;
int option;

while(1)
{
	printf("Enter a character:");
	c=getchar();

	//Clear buffer
	while(getchar() != '\n');

	//Display menu
	printf("1.Alphanumeric character.\n");
	printf("2.Alphabets.\n");
	printf("3.ASCII character.\n");
	printf("4.Blank character.\n");
	printf("5.Control character.\n");
	printf("6.Digits.\n");
	printf("7.Graphical character.\n");
	printf("8.Lower case character.\n");
	printf("9.Printable character.\n");
	printf("10.Punctuation character.\n");
	printf("11.Space character.\n");
	printf("12.Upper case character.\n");
	printf("13.Hexadecimal number.\n");

	printf("Enter an option:");
	scanf("%d",&option);
	while(getchar() != '\n');

//Check for option and perform appropriate options
switch(option)
{

	case 1:
		isalnum_f(c);
		if(response)
			printf("It is alphanumeric character.\n");
		else
			printf("It is not alphanumeric character.\n");			
		break;

	case 2:
		isalpha_f(c);
		if(response)
			printf("It is alphabet character.\n");
		else
			printf("It is not alphabet character.\n");			
		break;

	case 3:
		isascii_f(c);
		if(response)
			printf("It is ASCII character.\n");
		else
			printf("It is not ASCII character.\n");			
		break;

	case 4:
		isblank_f(c);
		if(response)
			printf("It is blank character.\n");
		else
			printf("It is not blank character.\n");			
		break;

	case 5:
		iscntrl_f(c);
		if(response)
			printf("It is control character.\n");
		else
			printf("It is not control character.\n");			
		break;

	case 6:
		isdigit_f(c);
		if(response)
			printf("It is digit character.\n");
		else
			printf("It is not digit character.\n");			
		break;

	case 7:
		isgraph_f(c);
		if(response)
			printf("It is graphical character.\n");
		else
			printf("It is not graphical character.\n");			
		break;

	case 8:
		islower_f(c);
		if(response)
			printf("It is lowercase character.\n");
		else
			printf("It is not lowercase character.\n");			
		break;

	case 9:
		isprint_f(c);
		if(response)
			printf("It is printable character.\n");
		else
			printf("It is not printable character.\n");			
		break;

	case 10:
		ispunct_f(c);
		if(response)
			printf("It is punctuation character.\n");
		else
			printf("It is not punctuation character.\n");			
		break;

	case 11:
		isspace_f(c);
		if(response)
			printf("It is space character.\n");
		else
			printf("It is not space character.\n");			
		break;

	case 12:
		isupper_f(c);
		if(response)
			printf("It is uppercase character.\n");
		else
			printf("It is not uppercase character.\n");			
		break;

	case 13:
		isxdigit_f(c);
		if(response)
			printf("It is hexadecimal character.\n");
		else
			printf("It is not hexadecimal character.\n");			
		break;

	default:
		printf("You have enter wrong option.");
}

      
	//Ask user for options
	printf("Do you want to continue(Y/N):");
	char ch=getchar();
	while(getchar() != '\n');
	if(!(ch == 'Y' || ch == 'y'))
	{
		break;
	}
}


return 0;
}
