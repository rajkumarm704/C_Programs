#ifndef TYPES_H
#define TYPES_H


/* User defined types */
typedef unsigned int uint;


/* Status will be used in fn. return type */
typedef enum
{
    e_success,
    e_failure
} Status;

typedef struct _AddressBook
{
	char *name;
	char *address;
	char *age;
	char *phone;
	char *email;

	
	int option;
	int search_option;

	FILE *database_fp;
	char *database_fname;

	long int keyword_fpi;

} AddressBookStruct;

#endif
