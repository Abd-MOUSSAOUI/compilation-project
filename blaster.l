%{
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"
%}

%option nounput
%option noyywrap

identifier            [a-zA-Z_]+[0-9a-zA-Z_]*
number                ([0-9]|([1-9][0-9]*))

%%

{identifier}          { yylval.string = strdup(yytext); return ID; }
{number}              { yylval.value = atoi(yytext); return NUMBER; }

[-+*/=(){}<>,;]     { return *yytext; }


"++"                  { return INCR; }
"--"                  { return DECR; }

"=="                  { return EQ; }
">="                  { return GE; }
"<="                  { return LE; }
"||"                  { return OR; }
"!="                  { return NEQ; }
"&&"                  { return AND; }
"!"                   { return NOT; }


[\n]                  { return yytext[0]; }
.                     { printf("Caractere inconnu: %s", yytext); }

%%

// Free the memory allocated for Lex when we are done.
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}