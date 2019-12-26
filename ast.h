#ifndef __AST_H__
#define __AST_H__

typedef enum ast_type { AST_ID, AST_NUMBER, AST_ASIGN, AST_NEG, AST_INCR, AST_DECR, AST_GT, AST_LT, AST_GE, AST_LE, AST_EQ, AST_NEQ, AST_ADD, AST_MIN, AST_MUL, AST_DIV} ast_type;

typedef struct ast {
  ast_type type;
  union {
    int number;
    char* id;
    struct {
      struct ast* left;
      struct ast* right;
    };
  };
} ast;

ast* ast_new_operation(ast_type, ast*, ast*);
ast* ast_new_number(int);
ast* ast_new_id(char*);
void ast_free(ast*);

#endif