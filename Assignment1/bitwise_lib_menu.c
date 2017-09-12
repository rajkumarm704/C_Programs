#include<stdio.h>

//Get nbits function
int get_nbits(int hnum, int n)
{
	int mask=0,i;
	mask=((1<<n)-1);
	hnum=hnum&mask;
	return hnum;
//	printf("Number is: %x\n",hnum);
	return 0;
}

//Get nbits from position function
int get_nbits_from_pos(int hnum,int n,int position)
{

	int mask=0,iter=0,i,position_copy,result;

	position_copy=position;
	position--;

	iter=position*n;
	mask=((1<<n)-1)<<iter;	

	result=hnum&mask;
	result=result>>(iter);
	return result;

}

//Set nbits Function
int set_nbits(int hnum,int value,int bit_set)
{

	int mask=0,mask_2=0,i,value_temp;

	mask_2=((1<<bit_set)-1);	
	mask_2=~mask_2;
	mask=((1<<bit_set)-1);	
	
	hnum&=mask_2;	
	value_temp=value&mask;

	hnum |= value_temp;
	return hnum;
//	printf("Number is: %x\n",hnum);

}

//Toggle bits from position Function
int toggle_bits_from_position(int hnum,int n, int position)
{

	int mask=0,mask_copy=0,value,i,position_copy,result;

	position--;
	mask=((1<<n)-1)<<position;	
	result=hnum^mask;
	return result;
}

//Set nbit from position function
int set_nbits_from_position(int hnum,int n,int position, int value)
{

	int mask=0,mask_copy=0;
	int i,position_copy,result;

	position--;
	mask=((1<<n)-1)<<position;	
	mask_copy=mask;	
	mask=~mask;
	result=hnum&mask;
	value&=mask_copy;
	result=result|value;

	return result;
}


//Print bit function
void print_bit_func(int num)
{
	int i;
	for(i=31;i>=0;i--)
		(1<<i)&num?putchar('1'):putchar('0');
	printf("\n");
}


int main()
{

	int option;
	int n,hnum,position,result,bit_set,value;	
	char ch;


while(1)
{
	printf("****************************************************");
	printf("\nSelect a function from the below menu:\n");
	printf("1. Get nbits function.\n");
	printf("2. Get nbits from position function.\n");
	printf("3. Set nbits function.\n");
	printf("4. Toggle bits from position function.\n");
	printf("5. Set nbits from position function.\n");		
	printf("\n\nEnter an option:");
	
	scanf("%d",&option);
	while(getchar() != '\n');
	printf("****************************************************\n");

switch(option)
{
	case 1:
		{
			printf("Enter number: ");
			scanf("%d",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to get: ");
			scanf("%d",&n);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result=get_nbits(hnum,n);
			printf("\nResult is ");
			print_bit_func(result);
			break;
		}
	case 2:
		{
			printf("Enter number: ");
			scanf("%d",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to get: ");
			scanf("%d",&n);
			while(getchar() != '\n');
			printf("Enter position of bits to get: ");
			scanf("%d",&position);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result=get_nbits_from_pos(hnum,n,position);
			printf("\nResult is ");
			print_bit_func(result);

			break;
		}

	case 3:
		{
			printf("Enter number: ");
			scanf("%d",&hnum);
			while(getchar() != '\n');
			printf("Enter value: ");
			scanf("%x",&value);
			while(getchar() != '\n');
			printf("Enter number of bits to set: ");
			scanf("%d",&bit_set);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result=set_nbits(hnum,value,bit_set);
			printf("\nResult is ");
			print_bit_func(result);

			break;
		}

	case 4:
		{
			printf("Enter number: ");
			scanf("%x",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to toggle: ");
			scanf("%d",&n);
			while(getchar() != '\n');
			printf("Enter position of bits to toggle: ");
			scanf("%d",&position);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result=toggle_bits_from_position(hnum,n,position);
			printf("\nResult is ");
			print_bit_func(result);
			break;
		}

	case 5:
		{

			printf("Enter hex number: ");
			scanf("%x",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to get: ");
			scanf("%d",&n);
			while(getchar() != '\n');
			printf("Enter position of bits to get: ");
			scanf("%d",&position);
			while(getchar() != '\n');
			printf("Enter value: ");
			scanf("%x",&value);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);	

			//Print the result
			result=set_nbits_from_position(hnum,n,position,value);
			printf("\nResult is ");
			print_bit_func(result);

		}


	default:printf("You have entered wrong option. Please try again...");

}
	printf("****************************************************\n");
	//Ask user for options
	printf("Do you want to continue(Y/N):");
	ch=getchar();
	while(getchar() != '\n');
	if(!(ch == 'Y' || ch == 'y'))
	{
		break;
	}
}
	return 0;
}
