#ifndef __AST_H__
#define __AST_H__

typedef enum ast_type {
    AST_PROG,
    AST_FUNC,
    AST_BLOCK,
    AST_STMTL,
    AST_ARG,
    AST_PARAML,
    AST_DECL,
    AST_ID,
    AST_NUMBER,
    AST_DIM,
    AST_ARRAY,
    AST_ASIGN,
    AST_NEG,
    AST_INCR,
    AST_DECR,
    AST_GT,
    AST_LT,
    AST_GE,
    AST_LE,
    AST_EQ,
    AST_OR,
    AST_AND,
    AST_NOT,
    AST_NEQ,
    AST_ADD,
    AST_MIN,
    AST_MUL,
    AST_DIV,
    AST_RET,
    AST_EXPST,
    AST_CALL,
    AST_IF,
    AST_IF_ELSE,
    AST_FOR,
    AST_WHILE,
} ast_type;

typedef struct ast {
  ast_type type;
  union {
    int number;
    char* id;

    struct {
      struct ast* left;
      struct ast* mid_l;
      struct ast* mid_r;
      struct ast* right;
    } op;
  };
} ast;

ast* ast_new_fornary(ast_type, ast*, ast*, ast*, ast*);
ast* ast_new_trenary(ast_type, ast*, ast*, ast*);
ast* ast_new_operation(ast_type, ast*, ast*);
ast* ast_new_number(int);
ast* ast_new_id(char*);
void ast_free(ast*);
void ast_print(ast*, int);


#endif
