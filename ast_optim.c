#include "ast_optim.h"


ast* ast_divide(ast* ast)
{
  while(ast)
  {
    switch (ast->type)
    {
      case AST_PROG:
        if(ast->right->left->type == AST_DEF)
          if(!strcmp(ast->right->left->left->id, "SPEC"))
            return ast;
        ast = ast->right;
        break;

      default: ast = ast->right; break;
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

    if(ast1->type == AST_FOR && ast2->type == AST_FOR)
    {
      return (  are_identical(ast1->left, ast2->left) 
             && are_identical(ast1->mid_l, ast2->mid_l)
             && are_identical(ast1->mid_r, ast2->mid_r)
             && are_identical(ast1->right, ast2->right) );
    }

    if(ast1->type == AST_ID && ast2->type == AST_ID)
      return 1;

    if(ast1->type == AST_ARR_DECL && ast2->type == AST_ARR_DECL)
      return 1;
      
    return (ast1->type == ast2->type
            && are_identical(ast1->left, ast2->left)
            && are_identical(ast1->right, ast2->right) );
}
   

int is_subtree(ast* ast1, ast* ast2)
{
    if (ast2 == NULL)
        return 1;

    if (ast1 == NULL)
        return 0;
    
    if(are_identical(ast1, ast2))
        return 1;
    
    if(ast1->type == AST_FUNC)
      return is_subtree(ast1->mid_r, ast2);

    if(ast1->type == AST_IF)
      return is_subtree(ast1->mid_l, ast2);
    
    if(ast1->type == AST_IF_ELSE)
      return is_subtree(ast1->mid_l, ast2) || is_subtree(ast1->mid_r, ast2);

    if(ast1->type == AST_BLOCK)
      return is_subtree(ast1->left, ast2);
    if(ast1->type == AST_PROG)
    {
      if(ast1->right != NULL) 
        return is_subtree(ast1->left, ast2) || is_subtree(ast1->right, ast2);
      else
        return is_subtree(ast1->left, ast2);
    }
    else
      return is_subtree(ast1->left, ast2) || is_subtree(ast1->right, ast2);
} 