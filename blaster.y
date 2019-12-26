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
%token INCR DECR EQ GE LE OR AND NOT NEQ
%type <ast> expr assign_expr unar_expr postfix_inc simp_expr add_expr term factor


%left '+' '-'
%left '*' '/'

%%
axiom:
  expr '\n'       { parser_ast = $1; return 0; }
  ;


expr:
    assign_expr      { $$ = $1; }
  | simp_expr        { $$ = $1; }
  ;

assign_expr:
    ID '=' expr      { $$ = ast_new_operation(AST_ASIGN, ast_new_id($1), $3); }
  | unar_expr        { $$ = $1; }
  ;

unar_expr:
    INCR ID          { $$ = ast_new_operation(AST_INCR, ast_new_id($2), NULL); }
  | DECR ID          { $$ = ast_new_operation(AST_DECR, ast_new_id($2), NULL); }
  | postfix_inc      { $$ = $1; }
  ;

postfix_inc:
    ID INCR         { $$ = ast_new_operation(AST_INCR, ast_new_id($1), NULL); }
  | ID DECR         { $$ = ast_new_operation(AST_DECR, ast_new_id($1), NULL); }
  ;

simp_expr:
    add_expr                  { $$ = $1; }
  | add_expr '>' add_expr   { $$ = ast_new_operation(AST_GT, $1, $3); }
  | add_expr '<' add_expr   { $$ = ast_new_operation(AST_LT, $1, $3); }
  | add_expr GE  add_expr   { $$ = ast_new_operation(AST_GE, $1, $3); }
  | add_expr LE  add_expr   { $$ = ast_new_operation(AST_LE, $1, $3); }
  | add_expr EQ  add_expr   { $$ = ast_new_operation(AST_EQ, $1, $3); }
  | add_expr NEQ add_expr   { $$ = ast_new_operation(AST_NEQ, $1, $3); }
  ;

add_expr:
    term                        { $$ = $1; }
  | add_expr '+' term      { $$ = ast_new_operation(AST_ADD, $1, $3); }
  | add_expr '-' term      { $$ = ast_new_operation(AST_MIN, $1, $3); }
  | '-' add_expr %prec '*' { $$ = ast_new_operation(AST_NEG, $2, NULL); }
  ;

term:
    factor           { $$ = $1; }
  | term '*' term    { $$ = ast_new_operation(AST_MUL, $1, $3); }
  | term '/' term    { $$ = ast_new_operation(AST_DIV, $1, $3); }
  ;

factor:
    '(' expr ')'     { $$ = $2; }
  | ID               { $$ = ast_new_id($1); }
  | NUMBER           { $$ = ast_new_number($1); }
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
