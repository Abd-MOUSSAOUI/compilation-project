%{
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"

  int end = 0;
%}

%option nounput
%option noyywrap

identifier            [a-zA-Z_][0-9a-zA-Z_]*
string                \"([^\"\\]|\\.)*\"
number                ([0-9]|([1-9][0-9]*))
array_id              [a-zA-Z][0-9a-zA-Z]*("["[^ =;,]"]" )+
comment               (\/\/.*)|("/*"([^*]|\*+[^*/])*\*+"/")
incl_str              ("<"[^<>\n]+">"|\"[^"\n]+\")
print_str             \"([^\"\\]|\\.)*\"(,[ ]*{identifier}(\[[{identifier}|{number}]\])*)*

%%

"if"                  { return IF; }
"else"                { return ELSE; }
"for"                 { return FOR; }
"while"               { return WHILE; }
"printf"              { return PRINTF; }
"int"                 { return INT; }
"void"                { return VOID; }
"const"               { return CONST; }
"return"              { return RET; }
"#include"            { return INCLUDE; }
"#define"             { return DEFINE; }

{incl_str}            { yylval.string = strdup(yytext); return STR; }
{print_str}           { yylval.string = strdup(yytext); return STR; }
{identifier}          { yylval.string = strdup(yytext); return ID; }
{number}              { yylval.value = atoi(yytext); return NUMBER; }
{comment}             {}


[-+*/=(){}<>,;\[\]]   { return *yytext; }

"++"                  { return INCR; }
"--"                  { return DECR; }

"=="                  { return EQ; }
">="                  { return GE; }
"<="                  { return LE; }
"||"                  { return OR; }
"!="                  { return NEQ; }
"&&"                  { return AND; }
"!"                   { return NOT; }

\n|\t|\r              { }
[ ]                   { }

<<EOF>>               { if(end)
                          yyterminate();

                        yyin = fopen("blast.c", "r");
                        yy_switch_to_buffer(yy_create_buffer(yyin, YY_BUF_SIZE));
                        end++;
                        BEGIN(INITIAL);
                      }

.                     { printf("Caractere inconnu: %s", yytext); }

%%

// Free the memory allocated for Lex when we are done.
void lex_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}
