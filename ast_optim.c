#include "ast_optim.h"

ast* ast_divide(ast* ast)
{
  while(ast)
  {
    switch (ast->type)
    {
      case AST_PROG:
        if(ast->op.right->op.left->type == AST_DEF)
          if(!strcmp(ast->op.right->op.left->op.left->id, "SPEC"))
            return ast;
        ast = ast->op.right;
        break;

      default: ast = ast->op.right; break;
    }
  }
  return NULL;
}

int are_identical(ast* ast1, ast* ast2)
{
    if (ast1 == NULL && ast2 == NULL)
      return 1;

    if (ast1 == NULL || ast2 == NULL)
      return 0;

    if(ast1->type == AST_ID && ast2->type == AST_ID)
      return 1;

    return (ast1->type == ast2->type
            && are_identical(ast1->op.left, ast2->op.left)
            && are_identical(ast1->op.right, ast2->op.right) );
}

int is_subtree(ast* ast1, ast* ast2)
{
    if (ast2 == NULL)
        return 1;

    if (ast1 == NULL)
        return 0;

    if (are_identical(ast1, ast2))
        return 1;

    return is_subtree(ast1->op.left, ast2) || is_subtree(ast1->op.right, ast2);
}
