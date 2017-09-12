#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"types.h"
#include"processing.h"

//Perform processing
Status perform_processing(Mp3DataStruct *mp3_struct)
{


	int ops_idx, i;
	char *ops[] = { "-t", "-T", "-a", "-A", "-y", "-c", "-g", "-h", "-v", "-d",  NULL };
//			  0     1     2     3     4     5     6     7     8     9     10


//	printf("In perform processing function\n");
	printf("\n");

	//Find and store all tags
	find_tags(mp3_struct);

	//Extract Album art
	extract_album_art(mp3_struct);

	mp3_struct->song_fp = fopen(mp3_struct->song_fname, "r+");

	if( mp3_struct->operation[0] == '*' )
	{
		printf("****************************************************************************\n");
		printf("name: %s", mp3_struct->song_fname);
		printf("\t\t\t\t size: %.2lf MB \n", mp3_struct->song_fsize);
		printf("****************************************************************************\n");

		printf("Title: %s\n", mp3_struct->title_tag );
		printf("Artist: %s\n", mp3_struct->artist_tag );
		printf("Album: %s\n", mp3_struct->album_tag );
		printf("Year: %s\n", mp3_struct->year_tag );

		printf("****************************************************************************\n");
		
	}
else
{
	if( strchr(mp3_struct->operation, 't') != NULL )
	{
/*		printf("Title tag: %s\n", mp3_struct->title_tag);
		printf("tag fpi:%ld\n", mp3_struct->title_tag_fpi);
		printf("tag count:%ld\n", mp3_struct->title_tag_count);
		printf("tag value:%s\n", mp3_struct->title_tag_val);
*/		
		sprintf(mp3_struct->title_tag_val, "%-*s", (int)mp3_struct->title_tag_count, mp3_struct->title_tag_val);
//		printf("value:%s*\n\n",mp3_struct->title_tag_val);
		fseek(mp3_struct->song_fp, mp3_struct->title_tag_fpi + 10, SEEK_SET);
		fwrite(mp3_struct->title_tag_val, 1, strlen(mp3_struct->title_tag_val) - 1, mp3_struct->song_fp);
//		printf("Write done\n\n");
	}
	if( strchr(mp3_struct->operation, 'a') != NULL )
	{

/*		printf("Artist tag: %s\n", mp3_struct->artist_tag);
		printf("tag fpi:%ld\n", mp3_struct->artist_tag_fpi);
		printf("tag count:%ld\n", mp3_struct->artist_tag_count);
		printf("tag value:%s\n", mp3_struct->artist_tag_val);
*/
		sprintf(mp3_struct->artist_tag_val, "%-*s", (int)mp3_struct->artist_tag_count, mp3_struct->artist_tag_val);
//		printf("value:%s*\n\n",mp3_struct->artist_tag_val);
		fseek(mp3_struct->song_fp, mp3_struct->artist_tag_fpi + 10, SEEK_SET);
		fwrite(mp3_struct->artist_tag_val, 1, strlen(mp3_struct->artist_tag_val) - 1, mp3_struct->song_fp);
//		printf("Write done\n\n");

	}
	if( strchr(mp3_struct->operation, 'A') != NULL )
	{
/*		printf("Album tag: %s\n", mp3_struct->album_tag);
		printf("tag fpi:%ld\n", mp3_struct->album_tag_fpi);
		printf("tag count:%ld\n", mp3_struct->album_tag_count);
		printf("tag value:%s\n", mp3_struct->album_tag_val);
*/
		sprintf(mp3_struct->album_tag_val, "%-*s", (int)mp3_struct->album_tag_count, mp3_struct->album_tag_val);
//		printf("value:%s*\n\n",mp3_struct->album_tag_val);
		fseek(mp3_struct->song_fp, mp3_struct->album_tag_fpi + 10, SEEK_SET);
		fwrite(mp3_struct->album_tag_val, 1, strlen(mp3_struct->album_tag_val) - 1, mp3_struct->song_fp);
//		printf("Write done\n\n");

	}
	if( strchr(mp3_struct->operation, 'y') != NULL )
	{
/*		printf("Year tag: %s\n", mp3_struct->year_tag);
		printf("tag fpi:%ld\n", mp3_struct->year_tag_fpi);
		printf("tag count:%ld\n", mp3_struct->year_tag_count);
		printf("tag value:%s\n", mp3_struct->year_tag_val);

*/
		sprintf(mp3_struct->year_tag_val, "%-*s", (int)mp3_struct->year_tag_count, mp3_struct->year_tag_val);
//		printf("value:%s*\n\n",mp3_struct->year_tag_val);
		fseek(mp3_struct->song_fp, mp3_struct->year_tag_fpi + 10, SEEK_SET);
		fwrite(mp3_struct->year_tag_val, 1, strlen(mp3_struct->year_tag_val) - 1, mp3_struct->song_fp);
//		printf("Write done\n\n");
	}


	//Display help information
	if( strcmp(mp3_struct->operation, ops[7] ) == 0 )
	{
		printf("usage: ./mp3reader.out -[tTaAycghv] \"new value\" filename.mp3\n"
			"./mp3reader.out -v\n"
			"-t	Modifies a Title tag\n"
			"-T	Modifies a Track tag\n"
			"-a	Modifies an Artist tag\n"
			"-A	Modifies an Album tag\n"
			"-y	Modifies a Year tag\n"
			"-c	Modifies a Comment tag\n"
			"-g	Modifies a Genre tag\n"
			"-h	Display Help information\n"
			"-v	Prints version info \n"
			"-d	Display file info \n"	);
	}	

}

}

Status validate_arguments(Mp3DataStruct *mp3_struct, int argc, char *argv[])
{
	int ops_idx, count = 0, ops_len, i, j;
	char ops[] = { "tTaAycghv" };

	//Validate arguments
	if( argc < 2 )
	{
		return e_failure;
	}
	else if ( argc >= 2)
	{
		//Store operation to perform
		if( argv[1] != NULL && strchr( argv[1], '-') != NULL )
		{
			mp3_struct->operation = argv[1];
			ops_len = strlen(mp3_struct->operation) - 1 ;
		}

		if(argc == ops_len + 1 + 2)
		{
			for( i = 1; i <= ops_len; i++)
			{
				switch( mp3_struct->operation[i] )
				{
					case 't': strcpy( mp3_struct->title_tag_val, argv[i+1]) ; break;
					case 'a': strcpy( mp3_struct->artist_tag_val, argv[i+1]); break;
					case 'A': strcpy( mp3_struct->album_tag_val, argv[i+1]); break;
					case 'y': strcpy( mp3_struct->year_tag_val, argv[i+1]); break;
				}
			}
			mp3_struct->song_fname = argv[ops_len + 2];
		}
	}

		if( *( argv[1] + 0) != '-' )
		{
			mp3_struct->operation = malloc( sizeof(char) );
			*( mp3_struct->operation + 0) = '*' ;
			mp3_struct->song_fname = argv[1];
		}

		return e_success;

}

					//Find and store tags
/****************************************************************************************************************/
Status find_tags(Mp3DataStruct *mp3_struct)
{
	int chSong, tag_idx = 0, iter = 0, limit = 0,count = 0, i;
	char tag[5], pre_tag[5];

	mp3_struct->song_fp = fopen( mp3_struct->song_fname, "r" );

	chSong = fgetc(mp3_struct->song_fp);

	while( strcmp( pre_tag, "APIC" ) != 0 )
	{
		if( chSong == 0x54 || chSong == 0x41 )
		{
			while( tag_idx != 4)
			{
				if( isprint(chSong) )
					tag[tag_idx] = chSong;

				chSong = fgetc(mp3_struct->song_fp);
				tag_idx++;
			}

			//TIT2 tag found
			if( strcmp( tag, "TIT2") == 0 )
			{
				//Store tag fpi
				mp3_struct->title_tag_fpi = ftell(mp3_struct->song_fp) - 4;

				while( limit != 4 )
				{
					count = count << 8;
					count |= chSong;
					chSong = fgetc(mp3_struct->song_fp);
					limit++;
				}

				//Store count
				mp3_struct->title_tag_count = count;

				//Readjust the fpi to first character
				fseek(mp3_struct->song_fp, 2l, SEEK_CUR);
				mp3_struct->title_tag = malloc( count * sizeof(char) );

				for( i = 0; i < count - 1; i++)
				{
					chSong = fgetc(mp3_struct->song_fp);
					*( mp3_struct->title_tag + i ) = chSong;
				}

				*( mp3_struct->title_tag + i ) = '\0';
				fseek(mp3_struct->song_fp, -1l, SEEK_CUR);
			}

			//TPE1 tag found
			if( strcmp( tag, "TPE1") == 0 )
			{
				//Store tag fpi
				mp3_struct->artist_tag_fpi = ftell(mp3_struct->song_fp) - 4;

				while( limit != 4 )
				{
					count = count << 8;
					count |= chSong;
					chSong = fgetc(mp3_struct->song_fp);
					limit++;
				}

				//Store count
				mp3_struct->artist_tag_count = count;

				//Readjust the fpi to first character
				fseek(mp3_struct->song_fp, 2l, SEEK_CUR);
				mp3_struct->artist_tag = malloc( count * sizeof(char) );

				for( i = 0; i < count - 1; i++)
				{
					chSong = fgetc(mp3_struct->song_fp);
					*( mp3_struct->artist_tag + i ) = chSong;
				}

				*( mp3_struct->artist_tag + i ) = '\0';
				fseek(mp3_struct->song_fp, -1l, SEEK_CUR);
			}

			//TALB tag found
			if( strcmp( tag, "TALB") == 0 )
			{
				//Store tag fpi
				mp3_struct->album_tag_fpi = ftell(mp3_struct->song_fp) - 4;

				while( limit != 4 )
				{
					count = count << 8;
					count |= chSong;
					chSong = fgetc(mp3_struct->song_fp);
					limit++;
				}

				//Store count
				mp3_struct->album_tag_count = count;

				//Readjust the fpi to first character
				fseek(mp3_struct->song_fp, 2l, SEEK_CUR);
				mp3_struct->album_tag = malloc( count * sizeof(char) );

				for( i = 0; i < count - 1; i++)
				{
					chSong = fgetc(mp3_struct->song_fp);
					*( mp3_struct->album_tag + i ) = chSong;
				}

				*( mp3_struct->album_tag + i ) = '\0';
				fseek(mp3_struct->song_fp, -1l, SEEK_CUR);
			}

			//TYER tag found
			if( strcmp( tag, "TYER") == 0 )
			{
				//Store tag fpi
				mp3_struct->year_tag_fpi = ftell(mp3_struct->song_fp) - 4;

				while( limit != 4 )
				{
					count = count << 8;
					count |= chSong;
					chSong = fgetc(mp3_struct->song_fp);
					limit++;
				}

				//Store count
				mp3_struct->year_tag_count = count;

				//Readjust the fpi to first character
				fseek(mp3_struct->song_fp, 2l, SEEK_CUR);
				mp3_struct->year_tag = malloc( count * sizeof(char) );

				for( i = 0; i < count - 1; i++)
				{
					chSong = fgetc(mp3_struct->song_fp);
					*( mp3_struct->year_tag + i ) = chSong;
				}

				*( mp3_struct->year_tag + i ) = '\0';
				fseek(mp3_struct->song_fp, -1l, SEEK_CUR);
			}
			strcpy( pre_tag, tag);
		}

		//Initialise variables to Initial condition
		tag[0] = '\0', count = 0, limit = 0, tag_idx = 0;

		chSong = fgetc(mp3_struct->song_fp);
		iter++;

	}

	//FPI of Album Art
	fseek(mp3_struct->song_fp, -6l, SEEK_CUR);
	mp3_struct->album_art_tag_fpi = ftell(mp3_struct->song_fp);

	fseek(mp3_struct->song_fp, 0l, SEEK_END);

	mp3_struct->song_fsize = ftell(mp3_struct->song_fp);
	
	mp3_struct->song_fsize /= 1024 * 1024;

	//Close file
	fclose( mp3_struct->song_fp );

}
/****************************************************************************************************************/

//Extract album art
Status extract_album_art(Mp3DataStruct *mp3_struct)
{
	int chSong = 0, chPreSong = 0, count = 0;
	int flag = 0;

	mp3_struct->song_fp = fopen( mp3_struct->song_fname, "r" );


	while(1)
	{
		chPreSong = chSong;
		chSong = fgetc(mp3_struct->song_fp);

		if( chPreSong == 0xff && chSong == 0xd8 && flag == 0)
		{
			flag = 1;
			mp3_struct->pic_start_fpi = ftell(mp3_struct->song_fp) - 2;
		}
		else if( chPreSong == 0xff && chSong == 0xd9 )
		{
			mp3_struct->pic_end_fpi = ( ftell(mp3_struct->song_fp) - 2 );
			break;
		}
	}

	mp3_struct->album_art_fp = fopen("album_art.jpg", "w");
	fseek( mp3_struct->song_fp, mp3_struct->pic_start_fpi, SEEK_SET);

	while(1)
	{
		if( ftell( mp3_struct->album_art_fp) <= mp3_struct->pic_end_fpi + 1)
		{
			chSong = fgetc(mp3_struct->song_fp);
			fputc(chSong, mp3_struct->album_art_fp);
		}
		else
			break;
	}

	fclose(mp3_struct->album_art_fp);
}














