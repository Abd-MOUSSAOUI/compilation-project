%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "ast.h"
  int yylex();
  void yyerror(char*);
  void lex_free();
  struct ast* parser_ast = NULL;
%}

%union {
  char* string;
  int value;
  struct ast* ast;
}

%token <string> ID
%token <value> NUMBER
%type <ast> expr

%left '+'
%left '*'

%%

axiom:
  expr '\n'       { parser_ast = $1; return 0; }
  ;

expr:
    expr '+' expr { $$ = ast_new_operation(AST_ADD, $1, $3); }
  | expr '*' expr { $$ = ast_new_operation(AST_MUL, $1, $3); }
  | '(' expr ')'  { $$ = $2; }
  | ID            { $$ = ast_new_id($1); }
  | NUMBER        { $$ = ast_new_number($1); }
  ;

%%

int main() {
  printf("Entrez une expression :\n");
  
  if (yyparse() == 0)
    ast_print(parser_ast, 0);

  // Be clean.
  lex_free();
  ast_free(parser_ast);
  return 0;
}
