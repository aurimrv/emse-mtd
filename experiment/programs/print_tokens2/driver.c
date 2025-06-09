#include    <stdio.h>
#include    <string.h>

# include "tokens.h"


void driver(int tc_number, int argc, char  *argv[])
{
   token tok;
   token_stream tp;
   char *fname;

   switch (tc_number)
   {
        case 0:
        fname = argv[1];
        tp=open_token_stream(fname);  /* open token stream */
        tok=get_token(tp);
        while (is_eof_token(tok) ==FALSE) /* take one token each time until eof */
        {
            print_token(tok);
            tok=get_token(tp);
        }
        print_token(tok); /* print eof signal */
        break;
        case 1:
        fname = argv[3];
        tp=open_token_stream(fname);  /* open token stream */
        tok=get_token(tp);
        while (is_eof_token(tok) ==FALSE) /* take one token each time until eof */
        {
            print_token(tok);
            tok=get_token(tp);
        }
        print_token(tok); /* print eof signal */
        printf("%d\n", (int) unget_char('a', tp));
        break;
        case 2:
        fname = argv[3];
        tp=open_token_stream(fname);  /* open token stream */
        printf("%d\n", (int) unget_char('\0', tp));
        tok=get_token(tp);
        print_token(tok); /* print eof signal */
        break;
        case 3:
        fname = argv[3];
        tp=open_token_stream(fname);  /* open token stream */
        tok=get_token(tp);
        while (is_eof_token(tok) ==FALSE) /* take one token each time until eof */
        {
	    printf("%s\n", (char *) tok);
            tok=get_token(tp);
        }
	printf("%s\n", (char *) tok);
        break;
   }
}
