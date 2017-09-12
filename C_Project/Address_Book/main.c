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
Status replace_content(AddressBookStruct *ab_struct, char *search_info);

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

			//Edit
			case 2:
				search_record(&ab_struct);
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
	
	//Open file in r+ mode
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}

	ab_struct->database_fp = fopen( ab_struct->database_fname, "a+" );


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
		fputc(user_data[i], ab_struct->database_fp);
		i++;
	}

	//Close file
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}
}

//Display data 
Status display_data(AddressBookStruct *ab_struct)
{
	int i = 0, ch, chPre;

	//Open file in r+ mode
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}

	ab_struct->database_fp = fopen( ab_struct->database_fname, "a+" );

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

	//Close file
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
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
	}

	search_word(ab_struct, search_info);

}


//Search Word
Status search_word(AddressBookStruct *ab_struct, char *search_info)
{
	int i = 0, ch, delimiter_count = 1, line_number = 1, line[100], j = 0, records_found_count = 0;
	char user_data[150], *str, user_data_t[150];

	//Open file in r+ mode
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}

	ab_struct->database_fp = fopen( ab_struct->database_fname, "r+" );


	fseek(ab_struct->database_fp, 0l, SEEK_SET);

	ch = fgetc(ab_struct->database_fp);

	//Display found row
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
				line[records_found_count] = line_number;
				printf("%d. %s\n",line_number, user_data);
				records_found_count++;
			}

			str = strtok( NULL, "|" );
			delimiter_count++;
		}

//		if( records_found_count == 0 )
//			printf("\t\t\tNo records found.\n");

		delimiter_count = 1;
		ch = fgetc(ab_struct->database_fp);
		line_number++;
	}
printf("*************************************************************************************************************\n");
	fseek(ab_struct->database_fp, 0l, SEEK_SET);

	//Replace content of file
	if( ab_struct->option == 2 )
	{
		if(records_found_count > 1 )
		{
			printf("Multiple records found. Please enter a better search criteria.\n");
			return e_failure;
		}
		else if(records_found_count == 1 )
		{
			replace_content(ab_struct, search_info);
			return e_success;
		}
	}

	//Delete records
	if(ab_struct->option == 5 )
		delete_user_info(ab_struct, line);

	//Close file
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}


}

//Delete user data
Status delete_user_info(AddressBookStruct *ab_struct, int *line)
{
	int ch, line_count = 1, line_idx = 0;
	long int char_count = 1, ii = 0;

	//Close file if it is open
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp);
		ab_struct->database_fp = NULL;
	}

	//Reopen file in r+ mode
	ab_struct->database_fp = fopen(ab_struct->database_fname, "r+");
	fseek(ab_struct->database_fp, 0l, SEEK_SET);

	//Fetch 1st character of file
	ch = fgetc(ab_struct->database_fp);

	while( ch != EOF )
	{
		while( ch != '\n')
		{
			ch = fgetc(ab_struct->database_fp);
			char_count++;
		}

		if( line_count == line[line_idx] && ch == '\n' )
		{
			fseek(ab_struct->database_fp, -char_count, SEEK_CUR );

			while(ii != char_count - 1)
			{
				fputc('*', ab_struct->database_fp);
				ii++;
			}
			line_idx++;
			fseek(ab_struct->database_fp, 1l, SEEK_CUR );
		}

		ch = fgetc(ab_struct->database_fp);

		fseek(ab_struct->database_fp, -1l, SEEK_CUR );

		char_count = 0;
		ii = 0;
		line_count++;
	}

	printf("Deletion completed\n");
	fclose(ab_struct->database_fp);
	ab_struct->database_fp = NULL;

	__fpurge(stdin);

	//Close file
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}

}


//Replace content of file
Status replace_content(AddressBookStruct *ab_struct, char *search_info)
{

	int i = 0, ch, delimiter_count = 0, char_count = 0, line_number = 1;
	char user_data[150], *str, new_info[100] ;

	long int name_len;
	long int age_len;
	long int address_len;
	long int phone_len;
	long int email_len;

	long int fpi = 1;
	long int actual_fpi = 1;

	int search_info_len = strlen(search_info);

	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}

	ab_struct->database_fp = fopen( ab_struct->database_fname, "r+" );

	fseek(ab_struct->database_fp, 0l, SEEK_SET);

	//Prompt user for information to change
/***************************************************************************************************************/
	char *menu[] = { "1. Name", "2. Age", "3. Address", "4. Phone", "5. email id",  NULL };
	int menu_idx = 0;

	printf("Choose the information to change:\n");
	
	while( menu[menu_idx] != '\0')
		printf("%s\n",menu[menu_idx++] );

	printf("\nEnter your option:"), scanf("%d", &ab_struct->search_option);
/***************************************************************************************************************/


	//Ask user for new data
	switch(ab_struct->search_option)
	{
		case 1:
			__fpurge(stdin);
			printf("\nEnter New Name:"),scanf("%[^\n]", new_info);
			break;

		case 2:
			__fpurge(stdin);
			printf("Enter New Age:"),scanf("%[^\n]", new_info);
			break;

		case 3:
			__fpurge(stdin);
			printf("Enter New Address:"),scanf("%[^\n]", new_info);
			break;

		case 4:
			__fpurge(stdin);
			printf("Enter New Phone Number:"),scanf("%[^\n]", new_info);
			break;

		case 5:
			__fpurge(stdin);
			printf("Enter New email ID:"),scanf("%[^\n]", new_info);
			break;

	}

	__fpurge(stdin);
	sprintf(new_info, "%-50.50s", new_info);

	ch = fgetc(ab_struct->database_fp);

	//Write data into row
	while( ch != EOF )
	{
		//Read 1st line
		for( i = 0; ch != '\n'; i++ )
		{
			if( ch == ';' )
				user_data[i] = '|';
			else
				user_data[i] = ch;

			ch = fgetc(ab_struct->database_fp);
			char_count++;
		}

		user_data[i] = '\0';

		str = strtok(user_data, "|");
		while( str != NULL )
		{
			switch(delimiter_count)
			{
				case 0: ab_struct->name = str;break;
				case 1: ab_struct->age = str;break;
				case 2: ab_struct->address = str;break;
				case 3: ab_struct->phone = str;break;
				case 4: ab_struct->email = str;break;

			}
			str = strtok( NULL, "|" );
			delimiter_count++;
		}

//		printf("\nname:%s\nage:%s\naddress:%s\nphone:%s\nemail:%s\n",ab_struct->name, ab_struct->age, ab_struct->address, ab_struct->phone, ab_struct->email );

		name_len = strlen(ab_struct->name);
		age_len = strlen(ab_struct->age);
		address_len = strlen(ab_struct->address);
		phone_len = strlen(ab_struct->phone);
		email_len = strlen(ab_struct->email);

		printf("char_count: %d\n", char_count);
//	printf("search info:%s\tage:%s\n", search_info, ab_struct->age);
		switch(ab_struct->search_option)
		{
			case 1: 
				printf("1. search option:%d\n", ab_struct->search_option);
				printf("1. new info:%s\tname:%s\n", new_info, ab_struct->name);
				actual_fpi = ftell(ab_struct->database_fp);
				fpi = ( ( char_count + 1 ) * (line_number - 1) ) ;

				if( strstr( ab_struct->name, search_info) != NULL )
				{
				printf("fpi: %ld\tactual fpi: %ld\tline number:%d\n",fpi, actual_fpi, line_number - 1 );
					fseek(ab_struct->database_fp, fpi, SEEK_SET);
					fwrite(new_info, 1, strlen(ab_struct->name), ab_struct->database_fp);
					fseek(ab_struct->database_fp, actual_fpi, SEEK_CUR);
				}
					
				break;
			case 2:
				printf("2. search option:%d\n", ab_struct->search_option);
				actual_fpi = ftell(ab_struct->database_fp);
				fpi = ( (char_count + 1) * (line_number - 1) ) + name_len + 1;

				if( strstr( ab_struct->age, search_info) != NULL )
				{
				printf("fpi: %ld\tactual fpi: %ld\tline number:%d\n",fpi, actual_fpi, line_number - 1 );
					fseek(ab_struct->database_fp, fpi, SEEK_SET);
					fwrite(new_info, 1, strlen(ab_struct->age), ab_struct->database_fp);
					fseek(ab_struct->database_fp, actual_fpi, SEEK_CUR);
				}
					
				break;
			case 3:
				printf("3. search option:%d\n", ab_struct->search_option);
				actual_fpi = ftell(ab_struct->database_fp);
				fpi = ( (char_count + 1) * (line_number - 1) ) + name_len + age_len + 2;

				if( strstr( ab_struct->address, search_info) != NULL )
				{
				printf("fpi: %ld\tactual fpi: %ld\tline number:%d\n",fpi, actual_fpi, line_number - 1 );
					fseek(ab_struct->database_fp, fpi, SEEK_SET);
					fwrite(new_info, 1, strlen(ab_struct->address), ab_struct->database_fp);
					fseek(ab_struct->database_fp, actual_fpi, SEEK_CUR);
				}
				break;

			case 4:
				printf("4. search option:%d\n", ab_struct->search_option);
				actual_fpi = ftell(ab_struct->database_fp);
				fpi = ( (char_count + 1) * (line_number - 1) ) + name_len + age_len + address_len + 3;

				if( strstr( ab_struct->phone, search_info) != NULL )
				{
				printf("fpi: %ld\tactual fpi: %ld\tline number:%d\n",fpi, actual_fpi, line_number - 1 );
					fseek(ab_struct->database_fp, fpi, SEEK_SET);
					fwrite(new_info, 1, strlen(ab_struct->phone), ab_struct->database_fp);
					fseek(ab_struct->database_fp, actual_fpi, SEEK_CUR);
				}
					
				break;

			case 5:
				printf("5. search option:%d\n", ab_struct->search_option);
				actual_fpi = ftell(ab_struct->database_fp);
				fpi = ( (char_count + 1) * (line_number - 1) ) + name_len + age_len + address_len + phone_len + 4;

				if( strstr( ab_struct->email, search_info) != NULL )
				{
				printf("fpi: %ld\tactual fpi: %ld\tline number:%d\n",fpi, actual_fpi, line_number - 1 );
					fseek(ab_struct->database_fp, fpi, SEEK_SET);
					fwrite(new_info, 1, strlen(ab_struct->email), ab_struct->database_fp);
					fseek(ab_struct->database_fp, actual_fpi, SEEK_CUR);
				}
					
				break;

		}
	

		delimiter_count = 0;
		ch = fgetc(ab_struct->database_fp);
		line_number++;
		char_count = 0;

	}
printf("*************************************************************************************************************\n");


	//Close file
	if( ab_struct->database_fp != NULL )
	{
		fclose(ab_struct->database_fp); 
		ab_struct->database_fp = NULL;
	}

}







