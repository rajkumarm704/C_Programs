#ifndef S2HTML_CONV_H
#define S2HTML_CONV_H

/********** function prototypes **********/

//HTML start function
void html_begin(FILE* dest_fp);

//HTML end function
void html_end(FILE* dest_fp);

//source to HTML converter
void source_to_html(FILE* fp, EventStruct *event_struct);

//Find keywords in source file and get events 
void get_events(FILE *source_fp, EventStruct *event_struct);


#endif

