#include "ast_optim.h"

ast* ast_divide(ast* ast) 
{
  while(ast) 
  {
    switch (ast->type) 
    {
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

int are_identical(ast* ast1, ast* ast2) 
{ 
    if (ast1 == NULL && ast2 == NULL) 
        return 1; 
  
    if (ast1 == NULL || ast2 == NULL) 
        return 0; 
    printf("ast1->type === %u\n", ast1->type);
    printf("ast2->type === %u\n", ast2->type);
    return (ast1->type == ast2->type   && 
            are_identical(ast1->op.left, ast2->op.left) && 
            are_identical(ast1->op.right, ast2->op.right) ); 
} 

int is_subtree(ast* ast1, ast* ast2) 
{
    if (ast2 == NULL) 
        return 1; 

    if (ast1 == NULL) 
        return 0; 
  
    if (are_identical(ast1, ast2)) 
        return 1; 
    return (is_subtree(ast1->op.left, ast2) || is_subtree(ast1->op.right, ast2));
} 