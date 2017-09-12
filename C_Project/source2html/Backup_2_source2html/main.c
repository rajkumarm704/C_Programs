#include <stdio.h>
#include<stdlib.h>

#include "s2html_event.h"
#include "s2html_conv.h"



int main (int argc, char *argv[])
{
	system("clear");

	FILE *source_fp, *html_fp; // source and destination file descriptors 

	EventStruct event_struct;

	char dest_fname[100], source_fname[100];

	int i = 0, data_read_limit;

	//Check for  arguments
	if(argc < 2)
	{
		printf("\nError ! please enter file name and mode\n");
		printf("Usage: <executable> <file name> \n");
		printf("Example : ./a.out abc.txt\n\n");
		return 1;
	}

	// Save name of source and html files
	if (argc > 2)
	{
		sprintf(source_fname, "%s", argv[1]);
		sprintf(dest_fname, "%s.html", argv[2]);
	}

	// open the source file
	if( (source_fp = fopen(source_fname, "r") ) == NULL )
	{
		printf("Error! File %s could not be opened\n", source_fname);
		return 2;
	}

	// open dest HTML file 
	if ( (html_fp = fopen(dest_fname, "w") ) == NULL )
	{
		printf("Error! could not create %s output file\n", dest_fname);
		return 3;
	}

	// write HTML starting Tags
	html_begin(html_fp);

	while(event_struct.event_cdata != 'Z' )
//	while( i != 50)
	{
		get_events(source_fp, &event_struct);

		if( event_struct.event_cdata == EOF )
			printf("EOF Reached\n");

		// call sourc_to_html 
		source_to_html(html_fp, &event_struct);
		i++;
	}

	// Call start_or_end_conv function for ending the convertation 
	html_end(html_fp);
	
	printf("\n########\nactual data:%s\n##########\n", event_struct.source_fdata);

	printf("\nOutput file %s generated\n", dest_fname);

	// close file 
	fclose(source_fp);
	fclose(html_fp);

	return 0;
}
