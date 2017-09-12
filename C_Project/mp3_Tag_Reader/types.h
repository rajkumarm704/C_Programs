#ifndef TYPES_H
#define TYPES_H


/* User defined types */
typedef unsigned int uint;
typedef unsigned long int lint;

/* Status will be used in fn. return type */
typedef enum
{
    	e_success,
    	e_failure,
	e_invalid_ops

} Status;

typedef struct _Mp3Data
{
	FILE *song_fp;
	char *song_fname;
	double song_fsize;

	char *operation;
	char *operation_arr;
	char *value;

	char *title_tag;
	char *artist_tag;
	char *album_tag;
	char *year_tag;


	char title_tag_val[100];
	char artist_tag_val[100];
	char album_tag_val[100];
	char year_tag_val[100];


	long int title_tag_fpi;
	long int artist_tag_fpi;
	long int album_tag_fpi;
	long int year_tag_fpi;
	long int album_art_tag_fpi;

	long int title_tag_count;
	long int artist_tag_count;
	long int album_tag_count;
	long int year_tag_count;

	FILE *album_art_fp;
	long int pic_start_fpi;
	long int pic_end_fpi;


} Mp3DataStruct;

#endif
