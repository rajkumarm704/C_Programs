#include <stdio.h>
#include<stdlib.h>

#include "s2html_event.h"
#include "s2html_conv.h"



int main (int argc, char *argv[])
{
	system("clear");

	FILE *source_fp;	

	EventStruct event_struct;

	char source_fname[100];

	int i = 0;

	//Check for  arguments
	if(argc < 1)
	{
		printf("\nError ! please enter file name\n");
		printf("Usage: <executable> <file name> \n");
		printf("Example : ./a.out abc.c\n\n");
		return 1;
	}

	// Save name of source and html files
	if (argc > 1)
	{
		sprintf(source_fname, "%s", argv[1]);
	}

	// open the source file
	if( (source_fp = fopen(source_fname, "r") ) == NULL )
	{
		printf("Error! File %s could not be opened\n", source_fname);
		return 2;
	}

	while(event_struct.event_cdata != '\0' )
	{
		get_events(source_fp, &event_struct);

		if( event_struct.event_cdata == EOF )
			printf("EOF Reached\n");

	}

	printf("\n#########################\nAnalysis complete\n#########################\n");
	
	// close file 
	fclose(source_fp);

	return 0;
}
