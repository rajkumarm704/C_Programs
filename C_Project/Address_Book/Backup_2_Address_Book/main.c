#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

#include"types.h"

void display_menu(AddressBookStruct *ab_struct);
void insert_names(AddressBookStruct *ab_struct);
Status display_data(AddressBookStruct *ab_struct);
Status search_record(AddressBookStruct *ab_struct);
Status search_word(AddressBookStruct *ab_struct, char *search_info);
Status delete_user_info(AddressBookStruct *ab_struct, int *line);
Status replace_content(AddressBookStruct *ab_struct, char *content, int *line_no_arr);

int main()
{
	system("clear");

	AddressBookStruct ab_struct;



	//Create & Open Database File
	ab_struct.database_fname = "database.txt";
	ab_struct.database_fp = fopen(ab_struct.database_fname, "a+");

	//Display menu
	display_menu(&ab_struct);

	while(1)
	{

		switch(ab_struct.option)
		{
			//Insert
			case 1:
				insert_names(&ab_struct);
				display_menu(&ab_struct);
				break;

			//Search
			case 3:
				search_record(&ab_struct);
				display_menu(&ab_struct);
				break;

			//Display
			case 4:
				display_data(&ab_struct);
				display_menu(&ab_struct);
				break;

			//Delete
			case 5:
				search_record(&ab_struct);
				display_menu(&ab_struct);
				break;

			//Exit
			case 6:
				if( ab_struct.database_fp != NULL )
					fclose(ab_struct.database_fp);
				return 0;

			default:
				printf("Invalid option. Please try again.\n");
				display_menu(&ab_struct);
		}
//		system("clear");
	}

	return 0;
}

//Display Menu
void display_menu(AddressBookStruct *ab_struct)
{
	char *menu[] = { "1. Insert", "2. Edit", "3. Search", "4. Display", "5. Delete", "6. Exit", NULL };
	int i = 0;

	printf("\n");
	
	while( menu[i] != '\0')
		printf("%s\n",menu[i++] );

	printf("\nEnter your option:"), scanf("%d", &ab_struct->option);

}

//Insert data into file
void insert_names(AddressBookStruct *ab_struct)
{
	int i = 0, data_len;
	char name[25], age[5], address[100], phone[20], email[50], user_data[200];
	
	printf("\nEnter details:\n\n");

	__fpurge(stdin);
	printf("\nEnter Name:"),scanf("%[^\n]", name);
	__fpurge(stdin);
	printf("Enter Age:"),scanf("%[^\n]", age);
	__fpurge(stdin);
	printf("Enter Address:"),scanf("%[^\n]", address);
	__fpurge(stdin);
	printf("Enter Phone Number:"),scanf("%[^\n]", phone);
	__fpurge(stdin);
	printf("Enter email ID:"),scanf("%[^\n]", email);

	sprintf(user_data,"%-30.25s;%-5.2s;%-20s;%-15.10s;%-20.20s\n", name,age,address,phone,email);
	user_data[strlen(user_data)] = '\0';
	data_len = strlen(user_data);

	while(user_data[i] != '\0')
	{
//		printf("%c",user_data[i]);
		fputc(user_data[i], ab_struct->database_fp);
		i++;
	}
}

//Display data 
Status display_data(AddressBookStruct *ab_struct)
{
	int i = 0, ch, chPre;

	if( ab_struct->database_fp == NULL )
		ab_struct->database_fp = fopen(ab_struct->database_fname, "a+");

	fseek( ab_struct->database_fp, 0l, SEEK_SET );
	ch = fgetc(ab_struct->database_fp);
	chPre = ch;

	printf("\n\n");
	while(ch != EOF)
	{
//		printf("( chPre:%c, ch:%c)\n", chPre, ch);
		if( ch == ';' )
		{
			printf("%c",'|');
			ch = fgetc(ab_struct->database_fp);
			chPre = ch;
			continue;
		}
		else if( chPre == '*' && ch == '\n' )
		{
			chPre = ch;
			ch = fgetc(ab_struct->database_fp);
			continue;
		}

		else if( ch == '*' )
		{
			chPre = ch;
			ch = fgetc(ab_struct->database_fp);
			continue;
		}
		else
			printf("%c",ch);

		chPre = ch;
		ch = fgetc(ab_struct->database_fp);
//		i++;
	}

	printf("\n\n");
}

//Search record
Status search_record(AddressBookStruct *ab_struct)
{
	char *menu[] = { "1. Name", "2. Age", "3. Address", "4. Phone", "5. email id", "6. Go Back",  NULL };
	int i = 0;
	static char search_info[20];
	
	printf("\n");
	
	printf("Enter you search criteria:\n");

	while( menu[i] != '\0')
		printf("%s\n",menu[i++] );

	printf("\nEnter your option:"), scanf("%d", &ab_struct->search_option);

	switch(ab_struct->search_option)
	{
		case 1:
			__fpurge(stdin);
			printf("\nEnter Name:"),scanf("%[^\n]", search_info);
			break;

		case 2:
			__fpurge(stdin);
			printf("Enter Age:"),scanf("%[^\n]", search_info);
			break;

		case 3:
			__fpurge(stdin);
			printf("Enter Address:"),scanf("%[^\n]", search_info);
			break;

		case 4:
			__fpurge(stdin);
			printf("Enter Phone Number:"),scanf("%[^\n]", search_info);
			break;

		case 5:
			__fpurge(stdin);
			printf("Enter email ID:"),scanf("%[^\n]", search_info);
			break;

		case 6:
			return e_success;

		default:
			printf("Invalid option. Please try again.\n");
//			search_record(&ab_struct);
	}

	search_word(ab_struct, search_info);

}


//Search Word
Status search_word(AddressBookStruct *ab_struct, char *search_info)
{
	int i = 0, ch, delimiter_count = 1, line_number = 1, line[100], j = 0;
	char user_data[150], *str, user_data_t[150];

	fseek(ab_struct->database_fp, 0l, SEEK_SET);

	ch = fgetc(ab_struct->database_fp);

printf("*************************************************************************************************************\n");
	while( ch != EOF )
	{
		for( i = 0; ch != '\n'; i++ )
		{
			if( ch == ';' )
				user_data[i] = '|', user_data_t[i] = '|';
			else
				user_data[i] = ch, user_data_t[i] = ch;

			ch = fgetc(ab_struct->database_fp);
		}

		user_data[i] = '\0';

		str = strtok(user_data_t, "|");
		while( str != NULL )
		{
			if( strstr( str, search_info) != NULL && delimiter_count == ab_struct->search_option )
			{
				line[j] = line_number;
				printf("%d. %s\n",line_number, user_data);
				j++;		 
			}

			str = strtok( NULL, "|" );
			delimiter_count++;
		}

		delimiter_count = 1;
		ch = fgetc(ab_struct->database_fp);
		line_number++;
	}
printf("*************************************************************************************************************\n");
	fseek(ab_struct->database_fp, 0l, SEEK_SET);

	if(ab_struct->option == 5 )
		delete_user_info(ab_struct, line);

}

//Delete user data
Status delete_user_info(AddressBookStruct *ab_struct, int *line)
{
	int i = 0, ch, line_count = 1, line_idx = 0, chData;
	long int char_count = 1, ii = 0;
//	FILE *temp_database_fp = NULL;

	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp);
		ab_struct->database_fp = NULL;
	}


	ab_struct->database_fp = fopen(ab_struct->database_fname, "r+");

	fseek(ab_struct->database_fp, 0l, SEEK_SET);
	ch = fgetc(ab_struct->database_fp);

	while( ch != EOF )
	{
		while( ch != '\n')
		{
			ch = fgetc(ab_struct->database_fp);
			char_count++;

//			printf("%ld ", ftell(ab_struct->database_fp) );
		}

//		printf("\nchar_count: %ld\n",char_count);

//		printf("\nline_count: %d\tline[%d]:%d\tch:%d\n", line_count, line_idx, line[line_idx], ch);
		if( line_count == line[line_idx] && ch == '\n' )
		{
//			printf("\nDeleting line %d\tfpi: %ld\n", line_count, ftell(ab_struct->database_fp));
			fseek(ab_struct->database_fp, -char_count, SEEK_CUR );
//			printf("\nDeleting fpi: %ld\n", ftell(ab_struct->database_fp));

			while(ii != char_count - 1)
			{
//				printf("%ld ", ftell(ab_struct->database_fp) );
				fputc('*', ab_struct->database_fp);
				ii++;
			}
			line_idx++;
			fseek(ab_struct->database_fp, 1l, SEEK_CUR );
		}
//		printf("\n********************************\n");

		ch = fgetc(ab_struct->database_fp);

		fseek(ab_struct->database_fp, -1l, SEEK_CUR );

//		printf("\nch: %d\n",ch);
		char_count = 0;
		ii = 0;
		line_count++;
	}

	printf("Deletion completed\n");
	fclose(ab_struct->database_fp);
	ab_struct->database_fp = NULL;

	__fpurge(stdin);
}

//Replace content of file
Status replace_content(AddressBookStruct *ab_struct, char *content, int *line_no_arr)
{

}







