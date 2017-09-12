/*

char* res_kwords_data[] = {"const", "volatile", "extern", "auto", "register",
   						   "static", "signed", "unsigned", "short", "long", 
						   "double", "char", "int", "float", "struct", 
						   "union", "enum", "void", "typedef", NULL
						  };

char* res_kwords_non_data[] = {"goto", "return", "continue", "break", 
							   "if", "else", "for", "while", "do", 
							   "switch", "case", "default","sizeof", NULL
							  };

char operators[] = {'/', '+', '*', '-', '%', '=', '<', '>', '~', '&', ',', '!', '^', '|', '\0'};
char symbols[] = {'(', ')', '{', '[', ':', '\0'};

*/

#ifndef S2HTML_EVENT_H
#define S2HTML_EVENT_H

typedef long int lint;
//typedef static int stint;

typedef struct _EventStruct
{
	char event_data[1024];
	char event_cdata;
	char *source_fdata;

	char source_tfdata[1024];

	long int start_fpi;
	long int end_fpi;

}EventStruct;


#endif

