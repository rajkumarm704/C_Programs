#ifndef S2HTML_EVENT_H
#define S2HTML_EVENT_H

typedef long int lint;
//typedef static int stint;

typedef enum
{
/*0*/	EVENT_NULL,
/*1*/	EVENT_PREPROCESSOR_DIRECTIVE,
/*2*/	EVENT_RESERVE_KEYWORD,
/*3*/	EVENT_NUMERIC_CONSTANT,
/*4*/	EVENT_STRING,
/*5*/	EVENT_HEADER_FILE,
/*6*/	EVENT_REGULAR_EXP,
/*7*/	EVENT_SINGLE_LINE_COMMENT,
/*8*/	EVENT_MULTI_LINE_COMMENT,
/*9*/	EVENT_ASCII_CHAR,
/*10*/	EVENT_CHAR,
/*11*/	EVENT_SPACE,
/*12*/	EVENT_TAB,
/*13*/	EVENT_ENTER,
/*14*/	EVENT_EOF
}event_e;

typedef struct _EventStruct
{
	event_e event_type; // event type
	char event_data[1024];
	char event_cdata;
	char *source_fdata;

	char source_tfdata[1024];

	long int start_fpi;
	long int end_fpi;

}EventStruct;


#endif

