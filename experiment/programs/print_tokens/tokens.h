/* *******************************************************************
    File name : tokens.h
    Purpose   : This is the header file for the tokenizer.c It
                contains the type definitions to be exported from
                the tokenizer.c.
 * ******************************************************************* */

# include "stream.h"

# define TRUE  1
# define FALSE 0
# define EOTSTREAM      0
# define NUMERIC        18
# define IDENTIFIER     17
# define LAMBDA         6
# define AND            9
# define OR             11
# define IF             13
# define XOR            16
# define LPAREN         19
# define RPAREN         20
# define LSQUARE        21
# define RSQUARE        22
# define QUOTE          23
# define BQUOTE         24
# define COMMA          25
# define EQUALGREATER   32
# define STRING_CONSTANT 27
# define CHARACTER_CONSTANT 29
# define ERROR             -1

typedef struct token_stream_type {
                             character_stream ch_stream;
                          } *token_stream;

typedef struct token_type {
                                int token_id;
                                char token_string[80];
                          } *token;

token_stream open_token_stream();

token get_token();

BOOLEAN compare_token();

BOOLEAN is_eof_token();


