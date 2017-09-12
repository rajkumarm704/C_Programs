#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdio_ext.h>

#include "s2html_event.h"
#include "s2html_conv.h"

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
char symbols[] = {'(', ')', '{', '}', '[', ']', ':', '\0'};

//Find keywords in source file and get event_structs 
void get_events(FILE *source_fp, EventStruct *event_struct)
{
	int chPre = 0, ch = 0, tfdata_idx = 0, i = 0;
	static int fdata_idx = 0,flag = 0;

	if( flag == 0)
	{
		fseek(source_fp, 0l, SEEK_END);
		lint source_fsize = ftell(source_fp);
		event_struct->source_fdata = malloc( source_fsize * sizeof(char) );
		fseek(source_fp, 0l, SEEK_SET);
		fread(event_struct->source_fdata, 1, source_fsize, source_fp);
		event_struct->source_fdata[source_fsize] = '\0';
		flag = 1;
	}

	while(1)
	{

		event_struct->event_cdata = event_struct->source_fdata[fdata_idx];

		if( event_struct->event_cdata == '\0' )
			return;

		if( event_struct->source_fdata[fdata_idx] == '\n' || event_struct->source_fdata[fdata_idx] == '\r' || event_struct->source_fdata[fdata_idx] == ' ' || event_struct->source_fdata[fdata_idx] == '\t'  )
		{	
			fdata_idx++;
			return;
		}


else if( event_struct->source_fdata[fdata_idx] >= 65 && event_struct->source_fdata[fdata_idx] <= 97 || event_struct->source_fdata[fdata_idx] >= 97 && event_struct->source_fdata[fdata_idx] <= 122 )
		{
			char word[10], i = 0, ii;
			while(1)
			{

				word[i] = event_struct->source_fdata[fdata_idx + i];
				i++;

 		if (event_struct->source_fdata[fdata_idx + i] == ';' || event_struct->source_fdata[fdata_idx + i] == ' ' || event_struct->source_fdata[fdata_idx + i] == '(' || event_struct->source_fdata[fdata_idx + i] == ',' || event_struct->source_fdata[fdata_idx + i] == ')')
			break;

			}

			word[i] = '\0';			
	
			for( ii = 0; res_kwords_data[ii] != NULL; ii++)
			{
				if( strcmp(word, res_kwords_data[ii]) == 0 )
				{
					printf("%s is a reserved keyword of data type\n", word);
					fdata_idx += i;
					return;
				}
			}

			for( ii = 0; res_kwords_non_data[ii] != NULL; ii++)
			{
				if( strcmp(word, res_kwords_non_data[ii]) == 0 )
				{
					printf("%s is a reserved keyword of non data type\n", word);
					fdata_idx += i ;
					return;
				}
			}

			printf("%s is a word\n", word);
			fdata_idx += i;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '/' && event_struct->source_fdata[fdata_idx + 1] == '/' )
		{
			event_struct->source_tfdata[0] = '/';
			event_struct->source_tfdata[1] = '/';
			for( i = 2; event_struct->source_fdata[fdata_idx + i] != '\r'; i++ )
			{
				event_struct->source_tfdata[i] = event_struct->source_fdata[fdata_idx + i];
			}
			event_struct->source_tfdata[i] = '\0';
			printf("%s \tis one line comment\n",event_struct->source_tfdata);

			fdata_idx += i;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '/' && event_struct->source_fdata[fdata_idx + 1] == '*' )
		{

			event_struct->source_tfdata[0] = '/';
			event_struct->source_tfdata[1] = '*';

			for( i = 2; event_struct->source_fdata[fdata_idx + i] != '*' && event_struct->source_fdata[fdata_idx + i] != '/'; i++ )
			{
				event_struct->source_tfdata[i] = event_struct->source_fdata[fdata_idx + i];
			}
			event_struct->source_tfdata[i] = '*';
			event_struct->source_tfdata[i + 1] = '/';
			event_struct->source_tfdata[i + 2] = '\0';
			printf("%s \tis multi line comment\n",event_struct->source_tfdata);

			fdata_idx += i + 3 ;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '#' )
		{
			event_struct->source_tfdata[0] = '#';
			for( i = 1; event_struct->source_fdata[fdata_idx + i] != '<'; i++)
			{
				event_struct->source_tfdata[i] = event_struct->source_fdata[fdata_idx + i];
			}

			event_struct->source_tfdata[i] = '\0';

			printf("%s is pre processor directive\n",event_struct->source_tfdata);
			fdata_idx += i;
			return;
		}


		else if( event_struct->source_fdata[fdata_idx] == '<' )
		{
			event_struct->source_tfdata[0] = '<';
			for( i = 1; event_struct->source_fdata[fdata_idx + i] != '>'; i++)
			{
				event_struct->source_tfdata[i] = event_struct->source_fdata[fdata_idx + i];
			}
			event_struct->source_tfdata[i] = '>';
			event_struct->source_tfdata[i + 1] = '\0';
			printf("%s is a header file\n",event_struct->source_tfdata);

			fdata_idx += i + 1;
			return;

		}
		else if( event_struct->source_fdata[fdata_idx] == '"' )
		{
			event_struct->source_tfdata[0] = '"';
			for( i = 1; event_struct->source_fdata[fdata_idx + i] != '"'; i++ )
			{
				event_struct->source_tfdata[i] = event_struct->source_fdata[fdata_idx + i];
			}

			event_struct->source_tfdata[i] = '"';
			event_struct->source_tfdata[i + 1] = '\0';

			printf("%s is a string.\n", event_struct->source_tfdata);
			fdata_idx += i + 1;
			return;
		}
		else
		{
			int ii;

			for( ii = 0; operators[ii] != '\0'; ii++)
			{
				if( event_struct->source_fdata[fdata_idx] == operators[ii] )
				{
					printf("%c is an operator\n", event_struct->source_fdata[fdata_idx]);
					fdata_idx++;
					return;
				}
			}
			for( ii = 0; symbols[ii] != '\0'; ii++)
			{
				if( event_struct->source_fdata[fdata_idx] == symbols[ii] )
				{
					printf("%c is a symbol\n", event_struct->source_fdata[fdata_idx]);
					fdata_idx++;
					return;
				}
			}
			if(event_struct->source_fdata[fdata_idx] == ';')
			{
				printf("%c is line termination character\n",event_struct->source_fdata[fdata_idx]);
				fdata_idx++;
				return;
			}
			if(event_struct->source_fdata[fdata_idx] >= 48 && event_struct->source_fdata[fdata_idx]<= 57 )
			{
				printf("%c is a number\n",event_struct->source_fdata[fdata_idx]);
				fdata_idx++;
				return;
			}
		

			printf("else\t");
			printf("%c\n",event_struct->source_fdata[fdata_idx]);
			fdata_idx++;
			return;
		}

		//Break while loop if nothing found
		break;
	}
}

