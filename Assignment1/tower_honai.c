#include<stdio.h>

int sort(int *num_arr, int *src_arr, int *dest_arr, int index, int i, int i_s, int i_d)
{

	//Return if all elements are moved from main array
	if(i==index)
	{
/*		printf("\nblock 4.\n");
		printf("index:%d, i:%d, i_s:%d, i_d:%d, ",index,i,i_s,i_d);

		printf("\nnum arr\n");

		int idx;
		for(idx=0;idx<index;idx++)
			printf("idx:%d, %d\n",idx,num_arr[idx]);
		
		printf("src arr\n");
		for(idx=0;idx<index;idx++)
			printf("idx:%d, %d \n",idx,src_arr[idx]);	

		printf("dest arr\n");
		for(idx=0;idx<index;idx++)
			printf("idx:%d, %d \n",idx,dest_arr[idx]);

		printf("\n");
		printf("Success in function.\n");
*/		return 1;
	}

	//Move the first element into source array
	if(i==0)
	{
/*		printf("\nblock 1.\n");
		printf("i:%d, i_s:%d, i_d:%d, ",i,i_s,i_d);
*/		src_arr[i_s]=num_arr[i];

//		printf("num_arr[%d]:%d, src_arr[%d]:%d \n",i,num_arr[i],i_s,src_arr[i_s]);
		i++;
		i_s++;
		sort(num_arr,src_arr,dest_arr,index,i,i_s,i_d);
	}
	
	//Move the next element from main array into source array onnly if former is smaller than 		//latter
	else if(src_arr[i_s-1]>num_arr[i])
	{
/*		printf("\nblock 2.\n");
		printf("i:%d, i_s:%d, i_d:%d, ",i,i_s,i_d);
*/		src_arr[i_s]=num_arr[i];

//		printf("num_arr[%d]:%d, src_arr[%d]:%d \n",i,num_arr[i],i_s,src_arr[i_s]);

		i_s++;
		i++;
		sort(num_arr,src_arr,dest_arr,index,i,i_s,i_d);
	}
	
	//Move the next element from main array into destination array onnly if former is smaller 		//than latter
	else if(dest_arr[i_d]>num_arr[i])
	{
/*		printf("\nblock 3.\n");
		printf("i:%d, i_s:%d, i_d:%d, ",i,i_s,i_d);
*/		dest_arr[i_d]=num_arr[i];

//		printf("num_arr[%d]:%d, dest_arr[%d]:%d \n",i,num_arr[i],i_d,dest_arr[i_d]);

		i_d++;
		i++;
		sort(num_arr,src_arr,dest_arr,index,i,i_s,i_d);
	}
}

//Initialise array function
void initialise_arr(int *arr, int index)
{
	int i;
	for(i=0;i<index;i++)
		arr[i]=999;
}

//Print array function
void print_arr(int *arr, int index)
{
	int i;
	printf("\nArray is: ");
	for(i=0;i<index;i++)
		printf("%d, ",arr[i]);	

	printf("\n\n");

}

//Re-arrange array function
void rearrange_arr(int *src_arr,int *dest_arr,int index)
{
	int i,i_s=0;
	printf("Re-arranged array :");
	for(i=0;i<index;i++)
	{
		if(dest_arr[i]==999)
		{
			dest_arr[i]=src_arr[i_s];
			i_s++;
		}
	
		printf("%d, ",dest_arr[i]);	
	}
	printf("\n");
}

//Copy array function
void copy_arr(int *s_arr, int *d_arr, int index)
{
	int i;
	for(i=0;i<index;i++)
		d_arr[i]=s_arr[i];
}

//Find if array is sorted function
int find_if_done(int *arr, int index)
{
	int i=0,count=0;
	for(i=0;i<index;i++)
	{
		if(arr[i]>arr[i+1] && i<index-2)
		{	count++;

//			printf("arr[%d]:%d, arr[%d]:%d ",i,arr[i],i+1,arr[i+1]);
//			printf("\nCount:%d\n",count);
		}
	}

	return count;
}


//Main function
int main()
{

//Declarations
int index,i,result=0,smallest,largest,stop_count=0;
char ch;

while(1)
{
	result=0;
	stop_count=0;
	index=0;

	//Prompt user for input
	printf("\nEnter the number of elements:");
	scanf("%d",&index);

	int num_arr[index],src_arr[index],dest_arr[index];

	printf("Enter the elements:");

	//Take array elements input from user
	for(i=0;i<index;i++)
		scanf("%d",&num_arr[i]);

	//Clear the buffer
	while(getchar() != '\n');

//	smallest=smallest_element(num_arr,index);
//	largest=largest_element(num_arr,index);

	//Label for repeating the whole process
	repeat:
	
	//Initialise array with a default value
	initialise_arr(src_arr,index);
	initialise_arr(dest_arr,index);

	//Send array for TOWER HONNAI sorting algorithm
	result=sort(num_arr,src_arr,dest_arr,index,0,0,0);

	//Re-arrange array after 1st sorting
	rearrange_arr(src_arr,dest_arr,index);

	//Check whether the array is sorted
	stop_count=find_if_done(dest_arr,index);

	//Check whether there is a need to send array for another sorting iteration
	if(result==1)
	{
		//If the array is sorted; print array
		if(stop_count==index-2)
		{
//			printf("Success in main function.\n");
			print_arr(dest_arr,index);
		}
		//If array is not sorted; send array for another iteration
		else
		{
			stop_count=0;
//			printf("Failure in main function.\n");
//			print_arr(dest_arr,index);
			copy_arr(dest_arr, num_arr,index);
			goto repeat;
		}		



	}

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
