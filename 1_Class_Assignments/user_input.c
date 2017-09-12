#include<stdio.h>
#include<string.h>
void main()
{
	char buffer[200]="";
	int age,id,len;
	char name[50],phone[15];


	printf("Enter Name:");
	scanf("%s",name);

	printf("Enter age:");
	scanf("%d",&age);

	printf("Enter ID:");
	scanf("%d",&id);

	printf("Enter phone number:");
	len = scanf("%s",phone);

	printf("Length:%d\n",len);

	if( strlen(phone) != 10 )
		strcpy(phone,"Invalid Entry");

	sprintf(buffer, "----------------------------------------\n"
			"\tVerify your input\n"
			"----------------------------------------\n"
			"Name		:	%s\n"
			"Age		:	%d\n"
			"ID		:	%d\n"
			"Phone		:	%s\n"
			"----------------------------------------\n",name,age,id,phone);

	printf("\n%s\n",buffer);


}
