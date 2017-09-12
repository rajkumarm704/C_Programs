#include<stdio.h>


//Print array function
void print_arr(int *arr, int index)
{
	int i;
	printf("Array is: ");
	for(i=0;i<index;i++)
		printf("%d, ",arr[i]);	

	printf("\n");

}

//Sort array
void sort_array(int *arr,int index)
{
	int i,j,temp,tnum;

	for(i=0;i<index;i++)
	{
		//Store the ith element in a temporary variable. This value will be checked with 			jth element of the array
		temp=arr[i];
		for(j=0;j<index;j++)
		{
			//ith element is less than jth element;swap the numbers
			if(temp<arr[j])
			{
				tnum=arr[i];
				arr[i]=arr[j];
				arr[j]=tnum;
			}				
		}
	}

	//Print array 
	print_arr(arr,index);
}

//Main function
int main()
{
	char ch;
	int index,i;
	float median,sum,result;

while(1)
{
	median=0;
	sum=0;
	result=0;

	//Prompt user for input
	printf("\nEnter the number of elements:");
	scanf("%d",&index);

	printf("Enter the elements:");

	int arr[index];

	for(i=0;i<index;i++)
		scanf("%d",&arr[i]);

	//Clear buffer
	while(getchar() != '\n');

	sort_array(arr,index);

	//Check whether the number of elements in array is even or odd
	if(index%2!=0)
	{
		//Middle number is median for odd case
		median=arr[((index+1)/2)-1];
	}
	else if(index%2==0)
	{
		median=(arr[(index/2)-1]+arr[((index/2)+1)-1])/2;
	}

	printf("Median is:%f\n",median);

	for(i=0;i<index;i++)
		arr[i]=arr[i]-median;

	print_arr(arr,index);

	for(i=0;i<index;i++)
		arr[i]=arr[i]*arr[i];

	print_arr(arr,index);

	for(i=0;i<index;i++)
		sum=sum+arr[i];

	printf("The sum is %f\n",sum);

	result=sum/index;

	printf("The variance is:%f\n",result);

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
