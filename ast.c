#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


ast* ast_new_operation(ast_type type, ast* left, ast* right) {
  ast* new = malloc(sizeof(ast));
  new->type = type;
  new->left = left;
  new->right = right;
  return new;
}

ast* ast_new_number(int number) {
  ast* new = malloc(sizeof(ast));
  new->type = AST_NUMBER;
  new->number = number;
  return new;
}

ast* ast_new_id(char* id) {
  ast* new = malloc(sizeof(ast));
  new->type = AST_ID;
  new->id = strdup(id);
  return new;
}

void ast_free(ast* ast) {
  switch (ast->type) {
    case AST_NUMBER:
      break;
    case AST_ID:
      free(ast->id);
      break;
    case AST_ADD:
      ast_free(ast->left);
      ast_free(ast->right);
      break;
    case AST_MUL:
      ast_free(ast->left);
      ast_free(ast->right);
      break;
  }
  free(ast);
}
