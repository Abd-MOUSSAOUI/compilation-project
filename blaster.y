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
%token IF ELSE FOR WHILE RET INT VOID
%token INCR DECR EQ GE LE OR AND NOT NEQ

%type <ast> prog external_decl func_decl param_l block stmt_l stmt expr_st if_st wh_st for_st ret_st var_decl expr assign_expr unar_expr postfix_inc simp_expr cond_expr add_expr term factor func_call args lhs array_access

%left '+' '-'
%left '*' '/'

%%
axiom:
  prog            { parser_ast = $1; return 0; }
  ;

prog:
    external_decl        { $$ = $1; }
  | prog external_decl   { $$ = ast_new_operation(AST_PROG, $1, $2); }

external_decl:
    var_decl             { $$ = $1; }
  | func_decl            { $$ = $1; }
  ;

func_decl:
    INT ID '(' ')' block            { $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), 0, $5); }
  | VOID ID '(' ')' block           { $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), 0, $5); }
  | INT ID '(' param_l ')' block    { $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), $4, $6); }
  | VOID ID '(' param_l ')' block   { $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), $4, $6); }
  ;

param_l:
    INT ID               { $$ = ast_new_id($2); }
  | VOID ID              { $$ = ast_new_id($2); }
  | INT ID ',' param_l   { $$ = ast_new_operation(AST_PARAML, ast_new_id($2), $4); }
  | VOID ID ',' param_l  { $$ = ast_new_operation(AST_PARAML, ast_new_id($2), $4); }
  ;

block:
    '{' '}'              { $$ = ast_new_operation(AST_BLOCK, 0, 0);}
  | '{' stmt_l '}'       { $$ = ast_new_operation(AST_BLOCK, $2, 0); }
  ;

stmt_l:
    stmt stmt_l          { $$ = ast_new_operation(AST_STMTL, $1, $2); }
  | stmt                 { $$ = $1; }
  ;

stmt:
    var_decl             { $$ = $1; }
  | expr_st              { $$ = $1; }
  | if_st                { $$ = $1; }
  | wh_st                { $$ = $1; }
  | for_st               { $$ = $1; }
  | ret_st               { $$ = $1; }
  ;

expr_st:
    ';'                  { $$ = ast_new_operation(AST_EXPST, 0, 0); }
  | expr ';'             { $$ = ast_new_operation(AST_EXPST, $1, 0); }
  ;

if_st:
    IF '(' expr ')' block              { $$ = ast_new_trenary(AST_IF, $3, $5, 0); }
  | IF '(' expr ')' block ELSE block   { $$ = ast_new_trenary(AST_IF_ELSE, $3, $5, $7); }
  ;

wh_st:
    WHILE '(' expr ')' block           { $$ = ast_new_operation(AST_WHILE, $3, $5); }
  ;

for_st:
    FOR '(' assign_expr ';' cond_expr ';' unar_expr ')' block   { $$ = ast_new_fornary(AST_FOR, $3, $5, $7, $9); }
  ;

ret_st:
    RET ';'              { $$ = ast_new_operation(AST_RET, 0, 0); }
  | RET expr ';'         { $$ = ast_new_operation(AST_RET, $2, 0); }
  ;

var_decl:
    INT lhs ';'           { $$ = ast_new_operation(AST_DECL, $2, 0);

                           if (sym_search(symbol_tab, $2->op.left->id) != NULL) {
                              fprintf(stderr, "ERROR: %s is allready initialized\n", $2->op.left->id);
	                            exit(1);
                           } else {
                              sym_add(INT_S, &symbol_tab, $2->op.left->id, -1, 0);
                           } }
  | INT lhs '=' expr ';'  { $$ = ast_new_operation(AST_DECL, $2, $4);

                           if (sym_search(symbol_tab, $2->op.left->id) != NULL) {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", $2->op.left->id);
	                            exit(1);
                           } else {
                              sym_add(INT_S, &symbol_tab, $2->op.left->id, $4->number, 0);
                           } }
  ;

expr:
    assign_expr          { $$ = $1; }
  | simp_expr            { $$ = $1; }
  ;

assign_expr:
    lhs '=' expr         { $$ = ast_new_operation(AST_ASIGN, $1, $3);
                          sym_mod(&symbol_tab, $1->op.left->id, AS_VAL, $3->number); }
  | lhs '=' array_access { $$ = ast_new_operation(AST_ASIGN, $1, $3); }
  | unar_expr            { $$ = $1; }
  ;

unar_expr:
    INCR ID              { $$ = ast_new_operation(AST_INCR, ast_new_id($2), NULL);
                           sym_mod(&symbol_tab, $2, INCR_VAL, 1); }
  | DECR ID              { $$ = ast_new_operation(AST_DECR, ast_new_id($2), NULL);
                           sym_mod(&symbol_tab, $2, DECR_VAL, 1); }
  | postfix_inc          { $$ = $1; }
  ;

postfix_inc:
    ID INCR              { $$ = ast_new_operation(AST_INCR, ast_new_id($1), NULL);
                           sym_mod(&symbol_tab, $1, INCR_VAL, 1); }
  | ID DECR              { $$ = ast_new_operation(AST_DECR, ast_new_id($1), NULL);
                           sym_mod(&symbol_tab, $1, DECR_VAL, 1); }
  ;

simp_expr:
    add_expr             { $$ = $1; }
  | cond_expr            { $$ = $1; }
  ;

cond_expr:
    NOT add_expr   { $$ = ast_new_operation(AST_NOT, $2, 0); }
  | add_expr '>' add_expr   { $$ = ast_new_operation(AST_GT, $1, $3); }
  | add_expr '<' add_expr   { $$ = ast_new_operation(AST_LT, $1, $3); }
  | add_expr GE  add_expr   { $$ = ast_new_operation(AST_GE, $1, $3); }
  | add_expr LE  add_expr   { $$ = ast_new_operation(AST_LE, $1, $3); }
  | add_expr EQ  add_expr   { $$ = ast_new_operation(AST_EQ, $1, $3); }
  | add_expr OR  add_expr   { $$ = ast_new_operation(AST_OR, $1, $3); }
  | add_expr NEQ add_expr   { $$ = ast_new_operation(AST_NEQ, $1, $3); }
  | add_expr AND add_expr   { $$ = ast_new_operation(AST_AND, $1, $3); }
  ;

add_expr:
    term                    { $$ = $1; }
  | add_expr '+' term       { $$ = ast_new_operation(AST_ADD, $1, $3); }
  | add_expr '-' term       { $$ = ast_new_operation(AST_MIN, $1, $3); }
  | '-' add_expr %prec '*'  { $$ = ast_new_operation(AST_NEG, $2, NULL); }
  ;

term:
    factor               { $$ = $1; }
  | term '*' term        { $$ = ast_new_operation(AST_MUL, $1, $3); }
  | term '/' term        { $$ = ast_new_operation(AST_DIV, $1, $3); }
  ;

factor:
    '(' expr ')'         { $$ = $2; }
  | ID                   { $$ = ast_new_id($1);
                           if (sym_search(symbol_tab, $1) == NULL) {
                              fprintf(stderr, "ERROR: %s is not initialized\n", $1);
                              exit(1);
                           } }
  | NUMBER               { $$ = ast_new_number($1); }
  | func_call            { $$ = $1; }
  ;

lhs:
    ID                   { $$ = ast_new_operation(AST_ARRAY, ast_new_id($1), 0); }
  | array_access         { $$ = $1; }
  ;

array_access:
    ID '[' ']'           { $$ = ast_new_operation(AST_ARRAY, ast_new_id($1), 0); }
  | ID '[' add_expr ']'    { $$ = ast_new_operation(AST_ARRAY, ast_new_id($1), $3); }
  ;

func_call:
    ID '(' ')'           { $$ = ast_new_operation(AST_CALL, ast_new_id($1), 0); }
  | ID '(' args ')'      { $$ = ast_new_operation(AST_CALL, ast_new_id($1), $3); }
  ;

args:
    expr                 { $$ = ast_new_operation(AST_ARG, $1, 0); }
  | expr ',' args        { $$ = ast_new_operation(AST_ARG, $1, $3); }
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
  //  ast_print(parser_ast, 0);
  //printf("\n");
  //sym_print(symbol_tab);
  printf("\n");
  gencode(parser_ast);
  fclose(input);

  // Be clean.
  lex_free();
  ast_free(parser_ast);
  sym_free(symbol_tab);
  return 0;
}
