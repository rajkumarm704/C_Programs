//ss2html_conv file

	while(1)
	{

		if( source_fdata[i] 

		if( chPre == '/' && ch == '*' )
		{
			event_struct->start_fpi = ftell(source_fp) - 2;
			printf("double line comment start fpi:%ld\n", event_struct->start_fpi );
		}		
		else if( chPre == '*' && ch == '/' )
		{
			event_struct->end_fpi = ftell(source_fp) ;
			printf("double line comment end fpi:%ld\n", event_struct->end_fpi );
			event_struct->event_type = EVENT_MULTI_LINE_COMMENT;

			break;
		}
		chPre = ch;
		ch = fgetc(source_fp);
	}


//main file

	html_begin(html_fp);

	while(1)
	{
		//get_events(source_fp, &event_struct);		
		get_events(source_fp, &event_struct);
		
/*		data_read_limit = (int)event_struct.end_fpi - (int)event_struct.start_fpi ;

		fseek(source_fp, event_struct.start_fpi, SEEK_SET);	

		fread(event_struct.event_data, 1, data_read_limit, source_fp);

		printf("data:%s\n", event_struct.event_data);

		// call sourc_to_html 
		source_to_html(html_fp, &event_struct);
*/
		break;
	}

	// Call start_or_end_conv function for ending the convertation 
	html_end(html_fp);


//	printf("File data:\n\n%s\n**********\n", event_struct->source_fdata);

/*	printf("data in int\n");
	while(event_struct->source_fdata[fdata_idx] != 'Z')
	{
		printf("%d ",event_struct->source_fdata[fdata_idx] );
		fdata_idx++;
	}
	printf("\n********\n");

	fdata_idx = 0;

	printf("data in char\n********\n");
	while(event_struct->source_fdata[fdata_idx] != 'Z')
	{
		printf("%c",event_struct->source_fdata[fdata_idx] );
		fdata_idx++;
	}
	printf("\n********\n");


	return;
*/
