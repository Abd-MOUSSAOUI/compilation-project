#include "ast_optim.h"

ast* ast_divide(ast* ast) {
  struct ast* result;

  switch (ast->type) {
    case AST_PROG:
        printf("%s\n", );
        ast = ast->op.right;
      }
      break;
    default:;
  }
  return result;
}

void ast_set(ast* src_ast, ast* blst_ast) {
  ast* node = ast_divide(src_ast);
  blst_ast = node->op.right;
  node->op.right = 0;
}
