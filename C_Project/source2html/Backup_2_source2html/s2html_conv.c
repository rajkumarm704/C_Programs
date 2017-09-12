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
char symbols[] = {'(', ')', '{', '[', ':', '\0'};

//HTML begin call function
void html_begin(FILE* html_fp)
{
	/* Add HTML begining tags into destination file */
	fprintf(html_fp, "<!DOCTYPE html>\n");
	fprintf(html_fp, "<html lang=\"en-US\">\n");
	fprintf(html_fp, "<head>\n");
	fprintf(html_fp, "<title>%s</title>\n", "sode2html");
	fprintf(html_fp, "<meta charset=\"UTF-8\">\n");
	fprintf(html_fp, "<link rel=\"stylesheet\" href=\"styles.css\">\n");
	fprintf(html_fp, "</head>\n");
	fprintf(html_fp, "<body style=\"background-color:black;\">\n");
	fprintf(html_fp, "<pre>\n");
}

//HTML end call function
void html_end(FILE* html_fp)
{
	/* Add HTML closing tags into destination file */
	fprintf(html_fp, "</pre>\n");
	fprintf(html_fp, "</body>\n");
	fprintf(html_fp, "</html>\n");
}


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
		flag = 1;
	}

	while(1)
	{
		if( event_struct->source_fdata[fdata_idx] == 'Z' )
		{	
			printf("EOF\t");
			event_struct->event_type = EVENT_NULL;
			event_struct->event_cdata = event_struct->source_fdata[fdata_idx];
//			event_struct->source_fdata[fdata_idx] = '\5';
			fdata_idx++;
			return;
		}

		if( event_struct->source_fdata[fdata_idx] == '\n' )
		{	
			printf("enter\t");
			event_struct->event_type = EVENT_ENTER;
			event_struct->event_cdata = '\n';
			event_struct->source_fdata[fdata_idx] = '\5';
			fdata_idx++;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '\r' )
		{	
			printf("enter\t");
			event_struct->event_type = EVENT_NULL;
			event_struct->event_cdata = '\r';
			event_struct->source_fdata[fdata_idx] = '\5';
			fdata_idx++;
			return;
		}
		if( event_struct->source_fdata[fdata_idx] == '\t' )
		{
			printf("tab\t");
			event_struct->event_type = EVENT_TAB;
			event_struct->event_cdata = '\t';
			event_struct->source_fdata[fdata_idx] = '\5';
			fdata_idx++;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == ' ' )
		{
			printf("space\t");
			event_struct->event_type = EVENT_SPACE;
			event_struct->event_cdata = ' ';
			event_struct->source_fdata[fdata_idx] = '\5';
			fdata_idx++;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] >= 65 && event_struct->source_fdata[fdata_idx] <= 97 || event_struct->source_fdata[fdata_idx] >= 97 && event_struct->source_fdata[fdata_idx] <= 122 )
		{
			printf("char\n");

			char word[10], i = 0, ii;
			while(1)
			{

				printf("%c",event_struct->source_fdata[fdata_idx + i]);
				word[i] = event_struct->source_fdata[fdata_idx + i];
				event_struct->source_fdata[fdata_idx + i] = '\5';

				i++;

 		if (event_struct->source_fdata[fdata_idx + i] == ';' || event_struct->source_fdata[fdata_idx + i] == ' ' || event_struct->source_fdata[fdata_idx + i] == '(' || event_struct->source_fdata[fdata_idx + i] == ',' || event_struct->source_fdata[fdata_idx + i] == ')')
			break;

			}

			word[i] = '\0';			
			i--;
			printf("\n********WORD---->%s\n", word);

/*			if(event_struct->source_fdata[fdata_idx + i] == ';')
			{
				event_struct->event_cdata = event_struct->source_fdata[fdata_idx];
				printf("%c\t",event_struct->event_cdata);
				event_struct->event_type = EVENT_CHAR;
				event_struct->source_fdata[fdata_idx] = '\5';
				fdata_idx++;

				return;
			}


			if(event_struct->source_fdata[fdata_idx + i] == '(')
			{
				event_struct->event_type = EVENT_FUNCTIONS;
				strcpy( event_struct->source_tfdata, word);
				fdata_idx += i;
				return;
			}

*/
			for( ii = 0; res_kwords_data[ii] != NULL; ii++)
			{
//				printf("%s %s\n", word, res_kwords_data[ii]);
				if( strcmp(word, res_kwords_data[ii]) == 0 )
				{
					printf("********MATCHED---->%s %s\n", word, res_kwords_data[ii]);
					event_struct->event_type = EVENT_RESERVE_KEYWORD;
					strcpy( event_struct->source_tfdata, word);
					fdata_idx += i;
					return;
				}
			}

			for( ii = 0; res_kwords_non_data[ii] != NULL; ii++)
			{
//				printf("%s %s\n", word, res_kwords_non_data[ii]);
				if( strcmp(word, res_kwords_non_data[ii]) == 0 )
				{
					printf("********MATCHED---->%s %s\n", word, res_kwords_non_data[ii]);
					event_struct->event_type = EVENT_RESERVE_KEYWORD;
					strcpy( event_struct->source_tfdata, word);
					fdata_idx += i ;
					return;
				}
			}

			strcpy( event_struct->source_tfdata, word);
			event_struct->source_fdata[fdata_idx] = '\5';
			event_struct->event_type = EVENT_YSTRING;
			fdata_idx += i + 1;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '/' && event_struct->source_fdata[fdata_idx + 1] == '/' )
		{
			printf("one line comment\t");

			event_struct->source_fdata[fdata_idx + 0] = '\5';
			event_struct->source_fdata[fdata_idx + 1] = '\5';

			event_struct->source_tfdata[0] = '/';
			event_struct->source_tfdata[1] = '/';
			for( i = 2, tfdata_idx = 2; event_struct->source_fdata[fdata_idx + i] != '\n'; i++, tfdata_idx++ )
			{

				//Write &lt; for <
				if(event_struct->source_fdata[fdata_idx + i] == '<')
				{
					event_struct->source_tfdata[tfdata_idx++] = '&';
					event_struct->source_tfdata[tfdata_idx++] = 'l';
					event_struct->source_tfdata[tfdata_idx++] = 't';
					event_struct->source_tfdata[tfdata_idx++] = ';';
					event_struct->source_fdata[fdata_idx + i] = '\5';
					i++;
				}
				//Write &gt; for >
				else if(event_struct->source_fdata[fdata_idx + i] == '>')
				{
					event_struct->source_tfdata[tfdata_idx++] = '&';
					event_struct->source_tfdata[tfdata_idx++] = 'g';
					event_struct->source_tfdata[tfdata_idx++] = 't';
					event_struct->source_tfdata[tfdata_idx++] = ';';
					event_struct->source_fdata[fdata_idx + i] = '\5';
					i++;
				}

				event_struct->source_tfdata[tfdata_idx] = event_struct->source_fdata[fdata_idx + i];
				event_struct->source_fdata[fdata_idx + i] = '\5';
			}

			event_struct->source_tfdata[tfdata_idx] = '\0';
			event_struct->source_fdata[fdata_idx + i] = '\5';
			event_struct->event_type = EVENT_SINGLE_LINE_COMMENT;
			fdata_idx = fdata_idx + i + 1;
			tfdata_idx = 0;

			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '/' && event_struct->source_fdata[fdata_idx + 1] == '*' )
		{

			printf("multi line comment\t");

			event_struct->source_fdata[fdata_idx + 0] = '\5';
			event_struct->source_fdata[fdata_idx + 1] = '\5';

			event_struct->source_tfdata[0] = '/';
			event_struct->source_tfdata[1] = '*';
for( i = 2; event_struct->source_fdata[fdata_idx + i] != '*' && event_struct->source_fdata[fdata_idx + i + 1] != '/'; i++ )
			{
				event_struct->source_tfdata[i] = event_struct->source_fdata[fdata_idx + i];
				event_struct->source_fdata[fdata_idx + i] = '\5';
			}

			//Delete the characters from buffer
			event_struct->source_fdata[fdata_idx + i] = '\5';
			event_struct->source_fdata[fdata_idx + i + 1] = '\5';
			event_struct->source_tfdata[i] = '*';
			event_struct->source_tfdata[i + 1] = '/';
			event_struct->source_tfdata[i + 2] = '\0';
			event_struct->event_type = EVENT_MULTI_LINE_COMMENT;
			fdata_idx += i + 2;
			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '#' )
		{
			printf("Pre processor\t");

			event_struct->source_fdata[fdata_idx + 0] = '\5';
			event_struct->source_tfdata[0] = '#';
			for( i = 1, tfdata_idx = 1; event_struct->source_fdata[fdata_idx + i] != '\n'; i++, tfdata_idx++ )
			{

				//Write &lt; for <
				if(event_struct->source_fdata[fdata_idx + i] == '<')
				{
					event_struct->source_tfdata[tfdata_idx++] = '&';
					event_struct->source_tfdata[tfdata_idx++] = 'l';
					event_struct->source_tfdata[tfdata_idx++] = 't';
					event_struct->source_tfdata[tfdata_idx++] = ';';
					event_struct->source_fdata[fdata_idx + i] = '\5';
					i++;
				}
				//Write &gt; for >
				else if(event_struct->source_fdata[fdata_idx + i] == '>')
				{
					event_struct->source_tfdata[tfdata_idx++] = '&';
					event_struct->source_tfdata[tfdata_idx++] = 'g';
					event_struct->source_tfdata[tfdata_idx++] = 't';
					event_struct->source_tfdata[tfdata_idx++] = ';';
					event_struct->source_fdata[fdata_idx + i] = '\5';
					i++;
				}

				event_struct->source_tfdata[tfdata_idx] = event_struct->source_fdata[fdata_idx + i];
				event_struct->source_fdata[fdata_idx + i] = '\5';
			}

			event_struct->source_tfdata[tfdata_idx] = '\0';
			event_struct->source_fdata[fdata_idx + i] = '\5';
			event_struct->event_type = EVENT_PREPROCESSOR_DIRECTIVE;
			printf("\ntfdata:%s\n", event_struct->source_tfdata);
			fdata_idx = fdata_idx + i + 1;
			tfdata_idx = 0;

			return;
		}
		else if( event_struct->source_fdata[fdata_idx] == '"' )
		{
			printf("String\t");

			event_struct->source_fdata[fdata_idx + 0] = '\5';
			event_struct->source_tfdata[0] = '"';
			for( i = 1; event_struct->source_fdata[fdata_idx + i] != '"'; i++ )
			{
				event_struct->source_tfdata[i] = event_struct->source_fdata[fdata_idx + i];
				event_struct->source_fdata[fdata_idx + i] = '\5';
			}

			event_struct->source_tfdata[i] = '"';
			event_struct->source_tfdata[i +  1] = '\0';
			event_struct->source_fdata[fdata_idx + i] = '\5';
			event_struct->event_type = EVENT_STRING;
			printf("\ntfdata:%s\n", event_struct->source_tfdata);
//			printf("\ntfdata:%s\n", event_struct->source_fdata);
			fdata_idx = fdata_idx + i + 1;
			return;
		}
		else
		{
			printf("else\t");
			event_struct->event_cdata = event_struct->source_fdata[fdata_idx];
			printf("%c\t",event_struct->event_cdata);
			event_struct->event_type = EVENT_CHAR;
			event_struct->source_fdata[fdata_idx] = '\5';
			fdata_idx++;
			return;
		}

		//Break while loop if nothing found
		break;
	}
}

// sourc_to_html function definitation
void source_to_html(FILE* html_fp, EventStruct *event_struct)
{
	//print event_struct
	if(event_struct->event_cdata == '\n' )
		printf("data:%d\t", event_struct->event_cdata);
	else if(event_struct->event_cdata == '\r' )
		printf("data:%d\t", event_struct->event_cdata);
	else
		printf("data:%c\t", event_struct->event_cdata);

	printf("event:%d\n", event_struct->event_type);

	switch(event_struct->event_type)
	{
		case EVENT_PREPROCESSOR_DIRECTIVE:
			fprintf(html_fp,"<span class=\"preprocess_dir\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_MULTI_LINE_COMMENT:
			fprintf(html_fp,"<span class=\"mcomment\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_SINGLE_LINE_COMMENT:
			fprintf(html_fp,"<span class=\"comment\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_STRING:
			fprintf(html_fp,"<span class=\"string\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_HEADER_FILE:
			fprintf(html_fp,"<span class=\"header_file\">&lt;%s&gt;</span>",event_struct->source_tfdata);
			break;

		case EVENT_REGULAR_EXP:
		case EVENT_EOF :
			fprintf(html_fp,"%s",event_struct->source_tfdata);
			break;

		case EVENT_NUMERIC_CONSTANT:
			fprintf(html_fp,"<span class=\"numeric_constant\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_RESERVE_KEYWORD:
			fprintf(html_fp,"<span class=\"reserved_key1\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_FUNCTIONS:
			fprintf(html_fp,"<span class=\"functions\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_ASCII_CHAR:
			fprintf(html_fp,"<span class=\"ascii_char\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_CHAR:
			fprintf(html_fp,"<span class=\"char\">%c</span>",event_struct->event_cdata);
			break;

		case EVENT_YSTRING:
			fprintf(html_fp,"<span class=\"char\">%s</span>",event_struct->source_tfdata);
			break;

		case EVENT_SPACE:
			fprintf(html_fp,"<span>%c</span>",event_struct->event_cdata);
			break;

		case EVENT_TAB:
			fprintf(html_fp,"<span>%c</span>",event_struct->event_cdata);
			break;

		case EVENT_ENTER:
			fprintf(html_fp,"<span>%c</span>",event_struct->event_cdata);
			break;
		case EVENT_NULL:
			break;
		default :
			printf("Unknow event_struct\n");
			break;
	}
}
/*raj*/
