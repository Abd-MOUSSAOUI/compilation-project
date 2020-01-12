%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <getopt.h>
  #include <string.h>
  #include "ast.h"
  #include "sym_tab.h"
  #include "gen_code.h"
  #include "ast_optim.h"
  #include "print_tree.h"

  int yylex();
  int std_inc = 0;
  int counter = 0, dim = 0, nb_args = 0, num_func = 0;
  FILE* yyin;
  FILE* blast;
  void yyerror(char*);
  void lex_free();
  struct sym_tab* symbol_tab = NULL;
  struct ast* parser_ast = NULL;
  struct ast* blast_ast = NULL;
  static int help_flag;
  int v = 0, t = 0, a = 0, o=0;
  char *o_flag_name = NULL;

  void getopts(int argc, char **argv)
  {
    int c;

    while (1)
      {
        static struct option long_options[] =
          {
            {"help", no_argument, &help_flag, 1},
            {"version", no_argument, 0, 'v'},
            {"tos", no_argument, 0, 't'},
            {"ast", no_argument, 0, 'a'},
            {"o_flag", required_argument, 0, 'o'},
            {0, 0, 0, 0}
          };
        /* getopt_long stores the option index here. */
        int option_index = 0;
        c = getopt_long(argc, argv, "vtao:", long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
          break;

        switch (c)
          {
          case 'o':
              o = 1;
              o_flag_name = optarg;
            break;
          case 'v':
              v = 1;;
            break;
          case 't':
              t = 1;;
            break;
          case 'a':
              a = 1;;
            break;
          case '?':
            if (optopt == 'c')
              fprintf(stderr, "Option -c requires an argument.\n");
            else
              fprintf(stderr, "Unknown option character\n");
            break;

          default:
            break;
          }
      }
    if(help_flag)
    {
        printf("\nOptions :\n");
        printf("--version indique les membres du groupe.\n");
        printf("--tos affiche la table des symboles.\n");
        printf("--ast affiche l’AST.\n");
        printf("--o <name> écris le code résultat dans le fichier name\n");
    }
    /* Print any remaining command line arguments (not options). */
  }

%}

%union {
  char* string;
  int value;
  struct ast* ast;
}

%token <string> ID STR
%token <value> NUMBER
%token IF ELSE FOR WHILE PRINTF RET INT VOID CONST INCLUDE DEFINE
%token INCR DECR EQ GE LE OR AND NOT NEQ

%type <ast> prog include define external_decl func_decl param_l param block stmt_l stmt expr_st if_st wh_st for_st print_stmt ret_st var_decl arr_arg expr assign_expr unar_expr postfix_inc simp_expr cond_expr add_expr term factor func_call args arr_acs dim empty_dim

%left '+' '-'
%left '*' '/'

%nonassoc UMINUS

%%
axiom:
  prog            { parser_ast = $1; return 0; }
  ;

prog:
    external_decl        { $$ = $1; }
  | external_decl prog   { $$ = ast_new_operation(AST_PROG, $1, $2); }

define:
    DEFINE ID           { $$ = ast_new_operation(AST_DEF, ast_new_id($2), 0);
                           if (sym_search(symbol_tab, INT_V, $2, -1) != NULL)
                           {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                              exit(1);
                           }
                           else
                           {
                              sym_add_var(INT_V, &symbol_tab, $2, -1, 0, -1, 1);
                           }
                        }
  | DEFINE ID NUMBER    { $$ = ast_new_operation(AST_DEF, ast_new_id($2), ast_new_number($3));
                          if (sym_search(symbol_tab, INT_V, $2, -1) != NULL)
                           {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                              exit(1);
                           }
                           else
                           {
                              sym_add_var(INT_V, &symbol_tab, $2, $3, 1, -1, 1);
                           }
                        }
  ;

include:
    INCLUDE STR          { $$ = ast_new_operation(AST_INCL, ast_new_id($2), 0);
                           if(!strcmp($2, "<stdio.h>"))
                              std_inc = 1;
                         }
  ;

external_decl:
    include              { $$ = $1; }
  | define               { $$ = $1; }
  | var_decl             { $$ = $1; }
  | func_decl            { $$ = $1; }
  ;

func_decl:
    INT ID '(' ')' block            { if (sym_search(symbol_tab,FUNC, $2,0) != NULL)
                                         {
                                            fprintf(stderr, "ERROR: %s function allready exist\n", $2);
                                            exit(1);
                                         }
                                         $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), 0, $5);
                                         sym_add_func(FUNC, 0, &symbol_tab, $2, 0, 0, num_func);
                                         num_func++;
                                       }
  | VOID ID '(' ')' block              { $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), 0, $5);
                                         if (sym_search(symbol_tab,FUNC, $2,0) != NULL)
                                         {
                                            fprintf(stderr, "ERROR: %s function allready exist\n", $2);
                                            exit(1);
                                         }
                                         else
                                         {
                                            sym_add_func(FUNC, 1, &symbol_tab, $2, 0, 0, num_func);
                                            num_func++;
                                         }
                                       }
  | INT ID '(' param_l ')' block    { if (sym_search(symbol_tab, FUNC, $2 , 0) != NULL)
                                         {
                                            fprintf(stderr, "ERROR: %s function allready exist\n", $2);
                                            exit(1);
                                         }
                                         else
                                         {
                                          $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), $4, $6);
                                          sym_add_func(FUNC, 0, &symbol_tab, $2, nb_args, 0, num_func);
                                          num_func++; nb_args = 0;
                                         }
                                    }
  | VOID ID '(' param_l ')' block   { $$ = ast_new_trenary(AST_FUNC, ast_new_id($2), $4, $6);
                                      if (sym_search(symbol_tab, FUNC, $2, 0) != NULL)
                                      {
                                        fprintf(stderr, "ERROR: %s function allready exist\n", $2);
                                        exit(1);
                                      }
                                      else
                                      {
                                        sym_add_func(FUNC, 1, &symbol_tab, $2, nb_args, 0,num_func);
                                        num_func++; nb_args = 0;
                                      }
                                    }
  ;

param_l:
    param               { $$ = $1; }
  | param ',' param_l   { $$ = ast_new_operation(AST_PARAML, $1, $3);
                          //if (sym_search(symbol_tab, INT_F, $2) != NULL)
                            //{
                              //fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
	                            //exit(1);
                           //}
                           //else
                           //{
                              //sym_add_var(INT_F, &symbol_tab, $2, -1, 0);
                           //}
                        }
  ;

param:
    INT ID               {  $$ = ast_new_operation(AST_PARAML, ast_new_id($2), 0);
                            if (sym_search(symbol_tab, INT_F, $2, num_func) != NULL)
                            {
                                fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                                exit(1);
                            }
                            else
                            {
                              nb_args++;
                              sym_add_var(INT_F, &symbol_tab, $2, -1, 0, num_func, 1);
                            }
                         }
  | INT ID dim           {  $$ = ast_new_operation(AST_PARAML, ast_new_operation(AST_ARRAY, ast_new_id($2), $3), 0);
                            if (sym_search(symbol_tab, INT_F, $2, num_func) != NULL)
                            {
                                fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                                exit(1);
                            }
                            else
                            {
                              nb_args++;
                              sym_add_var(INT_F, &symbol_tab, $2, -1, 0, num_func, 1);
                            }
                         }
  | INT ID empty_dim     {  $$ = ast_new_operation(AST_PARAML, ast_new_operation(AST_ARRAY, ast_new_id($2), $3), 0);
                            if (sym_search(symbol_tab, INT_F, $2, num_func) != NULL)
                            {
                                fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                                exit(1);
                            }
                            else
                            {
                              nb_args++;
                              sym_add_var(INT_F, &symbol_tab, $2, -1, 0, num_func, 1);
                            }
                         }
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
  | print_stmt           { $$ = $1; }
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

print_stmt:
    PRINTF '(' STR ')' ';'   { if(!std_inc) {
                                  fprintf(stderr, "implicitly declaring library function 'printf'");
                                  exit(1);
                               }
                               $$ = ast_new_operation(AST_PRINTF, ast_new_id($3), 0);
                             }
    ;

ret_st:
    RET ';'              { $$ = ast_new_operation(AST_RET, 0, 0); }
  | RET expr ';'         { $$ = ast_new_operation(AST_RET, $2, 0); }
  ;

var_decl:
    INT ID ';'        { if (sym_search(symbol_tab, INT_V, $2, num_func) != NULL)
                           {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                              exit(1);
                           }
                            sym_add_var(INT_V, &symbol_tab, $2, -1, 0, num_func, 0);
                            $$ = ast_new_operation(AST_DECL, ast_new_id($2), 0);
                      }
  | INT ID '=' expr ';'      { if (sym_search(symbol_tab, INT_V, $2, num_func) != NULL)
                               {
                                  fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                                  exit(1);
                               }
                               else
                               {
                                  int j = 0;
                                  if($4->type == AST_NUMBER)
                                    j = $4->number;
                                  else
                                    j = -1;
                                  sym_add_var(INT_V, &symbol_tab, $2, j, 0, num_func, 1);
                                  $$ = ast_new_operation(AST_DECL, ast_new_id($2), $4);
                               }
                             }
  | INT ID dim ';'    { if (sym_search(symbol_tab, TAB_INT, $2, num_func) != NULL)
                             {
                                fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                                exit(1);
                             }
                             $$ = ast_new_trenary(AST_ARR_DECL, ast_new_id($2), $3, 0);
                             sym_add_tab(TAB_INT, &symbol_tab, $2, dim, 0, num_func);
                             dim = 0;
                            }
  | INT ID dim '=' '{' arr_arg '}' ';' { if (sym_search(symbol_tab, TAB_INT, $2, num_func) != NULL)
                                            {
                                                fprintf(stderr, "ERROR: Re-definition of %s\n", $2);
                                                exit(1);
                                            }
                                            $$ = ast_new_trenary(AST_ARR_DECL, ast_new_id($2), $3, $6);
                                            sym_add_tab(TAB_INT, &symbol_tab, $2, dim, 0, num_func);
                                            dim = 0;
                                          }
  ;

arr_arg:
    expr                 { $$ = ast_new_operation(AST_ARR_ARG, $1, 0); }
  | expr ',' arr_arg     { $$ = ast_new_operation(AST_ARR_ARG, $1, $3); }
  ;

expr:
    assign_expr          { $$ = $1; }
  | simp_expr            { $$ = $1; }
  ;

assign_expr:
    ID '=' expr           { $$ = ast_new_operation(AST_ASIGN, ast_new_id($1), $3);
                          if($3->type == AST_NUMBER)
                            sym_mod(&symbol_tab, $1, AS_VAL, $3->number);
                          else
                            sym_mod(&symbol_tab, $1, AS_VAL, -1);
                          }
  | arr_acs '=' expr      {  if(!$1->right)
                            {
                              fprintf(stderr, "ERROR: invalid assignment\n");
                              exit(1);
                            }
                            $$ = ast_new_operation(AST_ASIGN, $1, $3);
                          }
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
  | '-' add_expr %prec UMINUS  { $$ = ast_new_operation(AST_NEG, $2, NULL); }
  ;

term:
    factor               { $$ = $1; }
  | term '*' term        { $$ = ast_new_operation(AST_MUL, $1, $3); }
  | term '/' term        { $$ = ast_new_operation(AST_DIV, $1, $3); }
  ;

factor:
    '(' expr ')'          { $$ = $2; }
  | ID                    { $$ = ast_new_id($1);
                            if (sym_search(symbol_tab, INT_V, $1, num_func) == NULL)
                            {
                              fprintf(stderr, "ERROR: %s is not initialized\n", $1);
                              exit(1);
                            }
                          }
  | NUMBER               { $$ = ast_new_number($1); }
  | func_call            { $$ = $1; }
  | arr_acs              { if(!$1->right) {
                             fprintf(stderr, "ERROR, unexpected expression\n");
                             exit(1);
                           }
                           $$ = $1; }
  ;

arr_acs:
    ID '[' ']'            { $$ = ast_new_operation(AST_ARRAY, ast_new_id($1), 0);
                            if (sym_search(symbol_tab, TAB_INT, $1, num_func) == NULL)
                            {
                              fprintf(stderr, "ERROR: %s doesn't exist\n", $1);
                              exit(1);
                            }
                          }
  | ID dim                { $$ = ast_new_operation(AST_ARRAY, ast_new_id($1), $2);
                            if (sym_search(symbol_tab, TAB_INT, $1, num_func) == NULL)
                            {
                              fprintf(stderr, "ERROR: %s doesn't exist++\n", $1);
                              exit(1);
                            }
                            dim = 0;
                          }
  ;

dim:
    '[' expr ']'            { $$ = ast_new_operation(AST_DIM, $2, 0);
                              dim++;
                            }
  | '[' expr ']'dim         { $$ = ast_new_operation(AST_DIM, $2, $4);
                              dim++;
                            }
  ;

empty_dim:
    '[' ']'                { $$ = ast_new_operation(AST_DIM, 0 ,0); }
  | '[' ']' empty_dim      { $$ = ast_new_operation(AST_DIM, 0, $3); }

func_call:
    ID '(' ')'          { $$ = ast_new_operation(AST_CALL, ast_new_id($1), 0);
                          if (sym_search(symbol_tab, FUNC, $1, 0) == NULL)
                          {
                            fprintf(stderr, "ERROR: %s function doesn't exist\n", $1);
                            exit(1);
                          }
                        }
  | ID '(' args ')'     { $$ = ast_new_operation(AST_CALL, ast_new_id($1), $3);
                          if (sym_search(symbol_tab, FUNC, $1,0) == NULL)
                          {
                            fprintf(stderr, "ERROR: %s function doesn't exist\n", $1);
                            exit(1);
                          }
                          if (check_args_nbr(symbol_tab, $1, counter) != 1)
                          {
                            fprintf(stderr, "ERROR: %s   Incorrect number of args\n",$1);
                            exit(1);
                          }
                        }
  ;

args:
    expr                { $$ = ast_new_operation(AST_ARG, $1, 0);
                          counter ++;
                        }
  | expr ',' args       { $$ = ast_new_operation(AST_ARG, $1, $3);
                          counter ++;
                        }
  ;

%%

int main(int argc, char** argv) {

  getopts(argc, argv);
  if(argc < 3) {
    fprintf(stderr, "Usage:\n./blaster src_file spec_file\n");
    exit(-1);
  }

  FILE* input = fopen(argv[1], "r");
  if(input == 0) {
    perror("error while opening file source");
    exit(-1);
  }

  blast = fopen(argv[2], "r");
  if(blast == 0) {
    perror("error while opening file spec");
    exit(-1);
  }

  yyin = input;

  if (yyparse() == 0) 
  {
    ast* tmp  = ast_divide(parser_ast);
    if(!tmp) {
      fprintf(stderr, "You must add '#define SPEC' on top of the spec file\n");
      exit(-1);
    }
    blast_ast = tmp->right->right;
    tmp->right = 0;

    if(v)
    {
        printf("\nAuthors:\n\n");
        printf("MOUSSAOUI Abderahmane (SDSC)\n");
        printf("BEGRICHE MASSINISSA (SIRIS)");
        printf("\n\n");
    }

    if(t)
    {
        sym_print(symbol_tab);
        printf("\n\n");
    }

    if(a)
    {
        print_ascii_tree(parser_ast);
        printf("\n\n");
    }

    optimizer(parser_ast, blast_ast);
    
    if(a)
    {
        print_ascii_tree(parser_ast);
        printf("\n\n");
    }

    if(o)
    {
        FILE *fp;
        if((fp=freopen(strcat(o_flag_name,".c"), "w" ,stdout))==NULL)
        {
          printf("Cannot open file.\n");
          exit(-1);
        }
        gencode(parser_ast, symbol_tab);
        fclose(fp);
    } 
    else
    {
        gencode(parser_ast, symbol_tab);
    }

  }

  fclose(input);

  // Be clean.
  lex_free();
  ast_free(parser_ast);
  sym_free(symbol_tab);
  return 0;
}
