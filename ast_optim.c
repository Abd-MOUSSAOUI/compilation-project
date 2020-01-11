#include "ast_optim.h"

ast* ast_divide(ast* ast) {
  while(ast) {
    switch (ast->type) {
      case AST_PROG:
        if(ast->op.left->type == AST_FUNC)
          if(!strcmp(ast->op.left->op.left->id, "main"))
            return ast;
        ast = ast->op.right;
        break;
      default: break;
    }
  }
  return NULL;
}
