#include<stdio.h>
int* my_itoa(int num,int *num_arr)
{
	int tnum,i;
	i=0;

	while(1)
	{
		num_arr[i]=num%10;
		num=num/10;
		if(num==0)
			break;
		i++;
	}

	return num_arr;
}

int my_atoi(char *str_ptr)
{
	int i_arr[20],i,num=0;
	int result=0;

	for(i=0;i<20;i++)
	{
		i_arr[i]=str_ptr[i];
		num=(int)i_arr[i];
		num-=48;
		if(num>=0 && num <= 9)
			result=result*10+num;
	}

	return result;
}

int main()
{

	int num,snum,tnum,count=1;
	int i,option;
	int *arr_ptr;
	char str[20];

	printf("Choose one of the following function:\n1.)itoa\n2.)atoi\n3.)get word.\n");
	scanf("%d",&option);

	if(option == 1)
	{
		printf("Enter the number:");
		scanf("%d",&num);
		tnum=num;
		while(1)
		{
			tnum=tnum/10;
			if(tnum!=0)
				count++;
			else if(tnum == 0)
				break;
		}
		int num_arr[count];
		arr_ptr=my_itoa(num,num_arr);	
		printf("Array is \n");
		for(i=count-1;i>=0;i--)
			printf("%d,",*(arr_ptr+i));		

		printf("\n");
	}
	else if(option == 2)
	{
		printf("Enter the character:");
		scanf("%s",str);
		i=my_atoi(str);
		printf("Number is %d\n",i);
	}
	else if(option==3)
	{
		printf("Enter the string:");
		scanf("%s",str);
		printf("The string is:%s\n",str);
	}

	return 0;
}
