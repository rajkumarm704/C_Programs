#include<stdio.h>

int check_sign(int lnum)
{
	int s_bit;

	if(lnum<0)
		s_bit=1;
	else
		s_bit=0;
	
	return s_bit;
}

int check_num_length(int num)
{
	int i,count=1;

	while(1)
	{
		num=num/10;
		if(num!=0)
			count++;
		else if(num == 0)
			break;
	}	
//printf("Count:%d\n",count);
	return count;
}


int main()
{

int lnum,rnum;
int s_bit,lnum_t,rnum_t,i;
int exp_arr[20];
int exponent=0;
int count,e_count,m_count=8;
int e_num,exp_num=0,man_num=0,m_num;
float fnum;
int temp=0,temp_sub;
int man_arr[20];
int multiplier=1;
int exp_act;
char ch;

while(1)
{
	printf("Enter lhs num and rhs num:");
	scanf("%d %d",&lnum,&rnum);

	while(getchar() != '\n');

	lnum_t=lnum;
	rnum_t=rnum;

	//Check whether the number is positive or negative
	s_bit=check_sign(lnum);

	i=0;

	//Calculate exponent part
	while(1)
	{
		exp_arr[i]=lnum_t%2;
	//	printf("element[%d].%d,lnum_t:%d\n",i,exp_arr[i],lnum_t);
		lnum_t=lnum_t/2;
		i++;
		e_count=i;
		if(lnum_t==0)
			break;
	}

	printf("\n");

	//Convert exponent number from int array to binary
	for(i=e_count;i>=0;i--)
	{
		e_num=exp_arr[i];
		exp_num=exp_num<<1;
		if(e_num == 1)
			exp_num|=1;
	}

	exp_act=127+e_count-1;


	//Pad 0 to bits with no value
	//exp_num=(exp_num<<(8-e_count));
	//printf("final exp_num:%x\n",exp_num);


	i=0;

	count=check_num_length(rnum);

	//Calculate multiplier for subtraction in mantissa calculation
	while(count)
	{
		multiplier=multiplier*10;
		count--;		
	}
	printf("Multiplier:%d\n",multiplier);

	//Calculate mantissa part
	while(1)
	{
		temp=rnum_t*2;
		temp_sub=multiplier-temp;
		if(temp_sub>0)
		{
			man_arr[i]=0;
			rnum_t=temp;
		}
		else
		{
			rnum_t=temp-100;
			man_arr[i]=1;
		}
		if(i==8)
			break;
	
	//	printf("temp_sub:%d,temp:%d,rnum:%d\n",temp_sub,temp,rnum);
		printf("man_arr[%d] is %d\n",i,man_arr[i]);
		i++;

	}

	//Convert mantissa number from int array to binary
	for(i=0;i<m_count;i++)
	{
		m_num=man_arr[i];
		man_num=man_num<<1;
		if(m_num == 1)
			man_num|=1;
	}



	//printf("final man_num:%x\n",man_num);


	printf("The result is: %d ",s_bit);

	for(i=7;i>=0;i--)
		(1<<i)&exp_act?putchar('1'):putchar('0');

	putchar(' ');

	for(i=7;i>=0;i--)
		(1<<i)&man_num?putchar('1'):putchar('0');


	printf("\n\n");

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

	
