#include<stdio.h>
#include<stdlib.h>
int main()

{

int ch;
int num,num_copy,a,b,tnum,mask,mask2,n,result;

while(1)
{
	printf("Enter the main number, a, b, and second number:");
	scanf("%x %d %d %x", &num,&a,&b,&tnum);
	num_copy=num;
	while(getchar() != '\n');	
	
	if(a < 0 && b > 31 && a > b)
	{
		printf("Invalid numbers. Please try again...");
		goto end;
	}	

	n=b-a+1;
	mask=(1<<n)-1;
	mask2=((1<<n)-1)<<a-1;
	mask2=~mask2;
	num_copy=num_copy&mask2;

	tnum=mask&tnum;
	tnum=tnum<<a-1;

	result=num_copy|tnum;
	printf("Result is %x\n",result);


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
