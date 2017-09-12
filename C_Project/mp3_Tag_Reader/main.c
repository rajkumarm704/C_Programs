#include<stdio.h>
#include<stdlib.h>
#include"types.h"

#include"processing.h"


int main(int argc, char *argv[])
{

	system("clear");

	Mp3DataStruct mp3_struct;
	Status status;

	status = validate_arguments(&mp3_struct, argc, argv);

	if( status == e_invalid_ops)
		printf("You have entered invalid operation. Please enter \"-h\" for help.\n\n");
	else if( status == e_success )
		printf("Commands are in entered in correct format.\n\n");
	else if( status == e_failure )
		printf("Invalid argument. Please enter the command in following format:\n"
			"command <-option> <value> <filename>\n\n");


	perform_processing(&mp3_struct);





	printf("\n\n");

	return 0;
}


















