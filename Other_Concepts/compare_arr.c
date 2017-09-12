#include<stdio.h>
int main()
{

	int i,index=5,greater=0,j;
	int count=0;
	int arr1[5],arr2[5];
	

	printf("Enter 5 elements for 2 arrays: ");

	for(i=0;i<index;i++)
	{
		scanf("%d %d",&arr1[i],&arr2[i]);
	}

for(j=0;j<index;j++)
{
	if(arr1[j]==arr2[j])
		count++;
	else
	{
		printf("Breaked at j:%d...\n",j+1);
		break;
	}
}		

	printf("Array1 is ");
	for(i=0;i<index;i++)
		printf("%d ",arr1[i]);

	printf("\n");

	printf("Array1 is ");
	for(i=0;i<index;i++)
		printf("%d ",arr2[i]);

	printf("\n");

	if(count==index)
		printf("Both arrays are equal.\n");
	else
		printf("Both arrays are not equal.\n");

	return 0;
}
