#include<stdio.h>
int main()
{

int count,i;

float fnum[10];

printf("Enter the total numbers:");
scanf("%d",&count);

printf("Enter the numbers:");

for(i=0;i<count;i++)
	scanf("%f",&fnum[i]);

printf("\n\n");
printf("Float array is ");

for (i = 0; i < count; i++ )
	printf("%.1f, ",fnum[i]);

printf("\n*****************************************\n");
int ii,j;
float temp;
float temp_copy=0,snum1=0,snum2=0,lnum1=0;


//Find largest number
for(j=0;j<count;j++)
{
	if (lnum1 > fnum[j])
		lnum1=lnum1;
	else if(fnum[j] > lnum1)
		lnum1=fnum[j];
}


//Find smallest number

for(i=0;i<count;i++)
{
	temp=lnum1;
	for(j=0;j<count;j++)
	{
		if (temp < fnum[j] && fnum[j] > snum1)
		{
//			printf("1* ");
			temp=temp;
		}
		else if(fnum[j] < temp && fnum[j] > snum1)
		{
			temp=fnum[j];
//			printf("2* ");
		}
	}

	printf("%.1f, ",temp);
//	printf("\n%.1f\n",temp);
	snum1=temp;
}

printf("\n\n");

return 0;
}
