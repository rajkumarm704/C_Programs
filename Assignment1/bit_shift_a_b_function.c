#include<stdio.h>
#include<stdlib.h>

//Bit shift function
int bit_shift_func(int num,int a,int b,int tnum)
{
	int num_copy,mask,mask2,n,result;
	num_copy=num;

	//Find out the number of bit positions to get mask
	n=b-a+1;
	mask=(1<<n)-1;
	mask2=((1<<n)-1)<<a-1;
	
	//Invert mask to clear appropriate bits
	mask2=~mask2;
	num_copy=num_copy&mask2;

	tnum=mask&tnum;
	tnum=tnum<<a-1;

	result=num_copy|tnum;
	
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

	int ch;
	int num,num_copy,a,b,tnum,mask,mask2,n,result;

while(1)
{
	printf("Enter the main number, a, b, and second number:");
	scanf("%x %d %d %x", &num,&a,&b,&tnum);

	printf("The number is ");
	print_bit_func(num);

	while(getchar() != '\n');	
	
	if(a < 0 && b > 31 && a > b)
	{
		printf("Invalid numbers. Please try again...");
		goto end;
	}	

	result=bit_shift_func(num,a,b,tnum);
	printf("Result is ");
	print_bit_func(result);

	//Ask user for options
end:	printf("\nDo you want to continue(Y/N):");
	ch=getchar();
	while(getchar() != '\n');
	if(!(ch == 'Y' || ch == 'y'))
	{
		break;
	}

}


return 0;
}
