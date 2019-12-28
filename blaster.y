%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "ast.h"
  #include "sym_tab.h"
  #include "gen_code.h"

  int yylex();
  FILE* yyin;
  void yyerror(char*);
  void lex_free();
  struct sym_tab* symbol_tab = NULL;
  struct ast* parser_ast = NULL;
%}

%union {
  char* string;
  int value;
  struct ast* ast;
}

%token <string> ID MAIN
%token <value> NUMBER
%token IF ELSE FOR WHILE RET INT
%token INCR DECR EQ GE LE OR AND NOT NEQ

%type <ast> main_func block stmt_l stmt if_st wh_st for_st for_init for_iter ret_st var_decl expr assign_expr unar_expr postfix_inc simp_expr cond_expr add_expr term factor

%left '+' '-'
%left '*' '/'

%%
axiom:
  main_func   { parser_ast = $1; return 0; }
  ;

main_func:
    INT MAIN block     { $$ = ast_new_operation(AST_FUNC, ast_new_id($2), $3); }
  ;

block:
    '{' '}'            { $$ = ast_new_operation(AST_BLOCK, 0, 0);}
  | '{' stmt_l '}'     { $$ = ast_new_operation(AST_BLOCK, $2, 0); }
  ;

stmt_l:
    stmt stmt_l        { $$ = ast_new_operation(AST_STMT, $1, $2); }
  | stmt               { $$ = $1; }
  ;

stmt:
    var_decl             { $$ = $1; }
  | expr ';'             { $$ = $1; }
  | if_st                { $$ = $1; }
  | wh_st                { $$ = $1; }
  | for_st               { $$ = $1; }
  | ret_st               { $$ = $1; }
  ;

if_st:
    IF '(' expr ')' block              { $$ = ast_new_trenary(AST_IF, $3, $5, 0); }
  | IF '(' expr ')' block ELSE block   { $$ = ast_new_trenary(AST_IF_ELSE, $3, $5, $7); }
  ;

wh_st:
    WHILE '(' expr ')' block            { $$ = ast_new_operation(AST_WHILE, $3, $5); }
  ;

for_st:
    FOR '(' for_init ';' cond_expr ';' for_iter ')' block   { $$ = ast_new_fornary(AST_FOR, $3, $5, $7, $9); }
  ;

for_init:
    ID '=' expr        { $$ = ast_new_operation(AST_ASIGN, ast_new_id($1), $3); }
  ;

for_iter:
    unar_expr          { $$ = $1; }
  | for_init           { $$ = $1; }
  ;


ret_st:
    RET ';'          { $$ = ast_new_operation(AST_RET, 0, 0); }
  | RET expr ';'     { $$ = ast_new_operation(AST_RET, $2, 0); }
  ;

var_decl:
    INT ID ';'          { $$ = ast_new_operation(AST_DECL, ast_new_id($2), 0); 
                        if (sym_search(symbol_tab, $2) != NULL)
                        {
                          fprintf(stderr, "ERROR: %s is allready initialized\n", $2);
	                        exit(1);
                        }
                        else
                        {
                          sym_add(INT_S, &symbol_tab, $2, -1, 0);
                        } 
                      }
  | INT ID '=' expr ';'  { $$ = ast_new_operation(AST_DECL, ast_new_id($2), $4);
                        if (sym_search(symbol_tab, $2) != NULL)
                        {
                          fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
	                        exit(1);
                        }
                        else
                        {
                          sym_add(INT_S, &symbol_tab, $2, $4->number, 0);
                        } 
                      }
  ;

expr:
    assign_expr      { $$ = $1; }
  | simp_expr        { $$ = $1; }
  ;

assign_expr:
    ID '=' expr      { $$ = ast_new_operation(AST_ASIGN, ast_new_id($1), $3);
                       sym_mod(&symbol_tab, $1, AS_VAL, $3->number); 
                     }
  | unar_expr        { $$ = $1; }
  ;

unar_expr:
    INCR ID         { $$ = ast_new_operation(AST_INCR, ast_new_id($2), NULL); 
                      sym_mod(&symbol_tab, $2, INCR_VAL, 1);   
                    }
  | DECR ID         { $$ = ast_new_operation(AST_DECR, ast_new_id($2), NULL); 
                      sym_mod(&symbol_tab, $2, DECR_VAL, 1);  
                    }
  | postfix_inc      { $$ = $1; }
  ;

postfix_inc:
    ID INCR         { $$ = ast_new_operation(AST_INCR, ast_new_id($1), NULL); 
                      sym_mod(&symbol_tab, $1, INCR_VAL, 1);   
                    }
  | ID DECR         { $$ = ast_new_operation(AST_DECR, ast_new_id($1), NULL); 
                      sym_mod(&symbol_tab, $1, DECR_VAL, 1);   
                    }
  ;

simp_expr:
    add_expr                  { $$ = $1; }
  | cond_expr                 { $$ = $1; }
  ;

cond_expr:
    add_expr '>' add_expr   { $$ = ast_new_operation(AST_GT, $1, $3); }
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
    '(' expr ')'    { $$ = $2; }
  | ID              { $$ = ast_new_id($1); 
                      if (sym_search(symbol_tab, $1) == NULL)
                      {
                        fprintf(stderr, "ERROR: %s is not initialized\n", $1);
                        exit(1);
                      }
                    }
  | NUMBER          { $$ = ast_new_number($1); }
  ;

%%

int main(int argc, char** argv) {

  FILE* input = fopen(argv[1], "r");
  if(input == 0) {
    perror("error while opening file");
    exit(-1);
  }

  yyin = input;

  if (yyparse() == 0)
    ast_print(parser_ast, 0);
  printf("\n");
  sym_print(symbol_tab);
  printf("\n");
  gencode(parser_ast);
  fclose(input);

  // Be clean.
  lex_free();
  ast_free(parser_ast);
  sym_free(symbol_tab);
  return 0;
}
