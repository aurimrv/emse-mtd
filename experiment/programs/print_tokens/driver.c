#include    <stdio.h>
#include    <string.h>

# include "tokens.h"


void driver(int tc_number, int argc, char  *argv[])
{
token token_ptr;
token_stream stream_ptr;
character_stream ch_stream;


   switch (tc_number)
   {
        case 0:
            stream_ptr=open_token_stream(argv[1]); /* neme of file */
            while(!is_eof_token((token_ptr=get_token(stream_ptr))))
                printf("%d\n", print_token(token_ptr));
            printf("%d\n", print_token(token_ptr));

        break;
        case 1:
            stream_ptr=open_token_stream(argv[3]); /* neme of file */
            unget_char('A', stream_ptr->ch_stream);
            while(!is_eof_token((token_ptr=get_token(stream_ptr))))
                printf("%d\n", print_token(token_ptr));
            printf("%d\n", print_token(token_ptr));

        break;
        case 2:
            stream_ptr=open_token_stream(NULL); /* neme of file */
        break;
        case 3:
            ch_stream=open_character_stream(NULL); /* neme of file */
            printf("%d \n", ch_stream->fp == stdin);
        break;
        case 4:
            stream_ptr=open_token_stream(argv[3]); /* neme of file */
            token_ptr=get_token(stream_ptr);
            print_token(token_ptr);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            while(!is_eof_token((token_ptr=get_token(stream_ptr))))
                printf("%d\n", print_token(token_ptr));
            printf("%d\n", print_token(token_ptr));
        break;
        case 5:
            stream_ptr=open_token_stream(argv[3]); /* neme of file */
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            while(!is_eof_token((token_ptr=get_token(stream_ptr))))
                printf("%d\n", print_token(token_ptr));
            printf("%d\n", print_token(token_ptr));
        break;
        case 6:
            stream_ptr=open_token_stream(argv[3]); /* neme of file */
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            unget_char('\0', stream_ptr->ch_stream);
            printf("%d \n", is_end_of_character_stream(stream_ptr->ch_stream));
        break;
        case 7:
            stream_ptr=open_token_stream(argv[3]); /* neme of file */
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            while(!is_eof_token((token_ptr=get_token(stream_ptr))))
                printf("%d\n", print_token(token_ptr));
            printf("%d\n", print_token(token_ptr));
        break;
        case 8:
            stream_ptr=open_token_stream(argv[3]); /* neme of file */
            token_ptr=get_token(stream_ptr);
            print_token(token_ptr);
            token_ptr=get_token(stream_ptr);
            print_token(token_ptr);
            token_ptr=get_token(stream_ptr);
            print_token(token_ptr);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            unget_char('A', stream_ptr->ch_stream);
            while(!is_eof_token((token_ptr=get_token(stream_ptr))))
                printf("%d\n", print_token(token_ptr));
            printf("%d\n", print_token(token_ptr));
        break;

   }
}
