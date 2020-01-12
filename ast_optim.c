#include "ast_optim.h"


void optimizer(ast* ast1, ast* blast)
{
  if(ast1 == NULL)
    return;
  ast* tmp = NULL;
  if(ast1 != NULL)
  {
    tmp = blast;
    switch(ast1->type)
    {
      case AST_PROG:
        optimizer(ast1->left,blast);
        optimizer(ast1->right,blast);
        break;
      case AST_FUNC:
        optimizer(ast1->mid_r,blast);
        break;
      case AST_BLOCK:
        if(ast1->left->type == AST_FOR) {
          while(tmp->type == AST_PROG || tmp->type == AST_FUNC)
          {
            if(tmp->type == AST_FUNC)
            {
              if(are_identical(ast1->left,ast_first_for(tmp)))
                ast1->left = ast_replace(ast1->left,tmp);
              break;
            }

            if(are_identical(ast1->left,ast_first_for(tmp->left)))
              ast1->left = ast_replace(ast1->left,tmp->left);
            tmp = tmp->right;
          }
        } else {
          optimizer(ast1->left,blast);
        }
        break;
      case AST_STMTL:
        if(ast1->left->type == AST_FOR) {
          while(tmp->type == AST_PROG || tmp->type == AST_FUNC)
          {
            if(tmp->type == AST_FUNC)
            {
              if(are_identical(ast1->left,ast_first_for(tmp)))
                ast1->left = ast_replace(ast1->left,tmp);
              break;
            }

            if(are_identical(ast1->left,ast_first_for(tmp->left)))
              ast1->left = ast_replace(ast1->left,tmp->left);
            tmp = tmp->right;
          }
        }

        if(ast1->right->type == AST_FOR) {
          while(tmp->type == AST_PROG || tmp->type == AST_FUNC)
          {
            if(tmp->type == AST_FUNC)
            {
              if(are_identical(ast1->right,ast_first_for(tmp)))
                ast1->right = ast_replace(ast1->right,tmp);
              break;
            }

            if(are_identical(ast1->right,ast_first_for(tmp->left)))
              ast1->right = ast_replace(ast1->right,tmp->left);
            tmp = tmp->right;
          }
        }

        optimizer(ast1->left,blast);
        optimizer(ast1->right,blast);
        break;
      // case AST_FOR:
      //     while(tmp->type == AST_PROG || tmp->type == AST_FUNC)
      //     {
      //       if(tmp->type == AST_FUNC)
      //       {
      //         if(are_identical(ast1,ast_first_for(tmp)))
      //           ast_replace(&ast1,tmp);
      //         break;
      //       }
      //
      //       if(are_identical(ast1,ast_first_for(tmp->left)))
      //         ast_replace(&ast1,tmp->left);
      //       tmp = tmp->right;
      //     }
      //   break;
      default:
        break;
    }
  }
}

ast* ast_first_for(ast* ast)
{
  while(ast)
  {
    switch (ast->type)
    {
      case AST_STMTL:
        if(ast->left->type == AST_FOR)
            return ast->left;
        if(ast->right->type == AST_FOR)
          return ast->right;
        if(ast->right->type == AST_STMTL)
          ast = ast->right;
        break;
      case AST_FUNC:
        ast = ast->mid_r;
        break;
      case AST_BLOCK:
        ast = ast->left;
        break;
      default: ast = ast->right; break;
    }
  }
  return NULL;
}

ast* ast_replace(ast* ast1, ast* ast2) {
  ast* result;
  if(!strcmp(ast2->left->id, "saxpy")) {
     ast *x, *a;
     ast* high = ast1->mid_l->right;
     ast* y    = ast1->right->left->left->left->left;

     if(ast1->right->left->left->right->left->type == AST_MUL) {
       if(ast1->right->left->left->right->left->left->type == AST_ARRAY) {
          x = ast1->right->left->left->right->left->left->left;
          a = ast1->right->left->left->right->left->right;
       } else {
          x = ast1->right->left->left->right->left->right->left;
          a = ast1->right->left->left->right->left->left;
       }
     } else {
       if(ast1->right->left->left->right->right->left->type == AST_ARRAY) {
          x = ast1->right->left->left->right->right->left->left;
          a = ast1->right->left->left->right->right->right;
       } else {
          x = ast1->right->left->left->right->right->right->left;
          a = ast1->right->left->left->right->right->left;
       }
     }


     result = ast_new_operation(AST_ARG, ast_new_number(1), 0);
     result = ast_new_operation(AST_ARG, y, result);
     result = ast_new_operation(AST_ARG, ast_new_number(1), result);
     result = ast_new_operation(AST_ARG, x, result);
     result = ast_new_operation(AST_ARG, a, result);
     result = ast_new_operation(AST_ARG, high, result);
     result = ast_new_operation(AST_CALL, ast_new_id("saxpy"), result);
     result = ast_new_operation(AST_EXPST, result, 0);
  }

  if(!strcmp(ast2->left->id, "sscal")) {
    ast* n = ast1->mid_l->right;
    ast* a = ast1->right->left->left->right->left;
    ast* x = ast1->right->left->left->left->left;

    result = ast_new_operation(AST_ARG, ast_new_number(1), 0);
    result = ast_new_operation(AST_ARG, x, result);
    result = ast_new_operation(AST_ARG, a, result);
    result = ast_new_operation(AST_ARG, n, result);
    result = ast_new_operation(AST_CALL, ast_new_id("sscal"), result);
    result = ast_new_operation(AST_EXPST, result, 0);
  }

  if(!strcmp(ast2->left->id, "scopy")) {
    ast* n = ast1->mid_l->right;
    ast* x = ast1->right->left->left->left->left;
    ast* y = ast1->right->left->left->right->left;

    result = ast_new_operation(AST_ARG, ast_new_number(1), 0);
    result = ast_new_operation(AST_ARG, y, result);
    result = ast_new_operation(AST_ARG, ast_new_number(1), result);
    result = ast_new_operation(AST_ARG, x, result);
    result = ast_new_operation(AST_ARG, n, result);
    result = ast_new_operation(AST_CALL, ast_new_id("scopy"), result);
    result = ast_new_operation(AST_EXPST, result, 0);
  }

  if(!strcmp(ast2->left->id, "sswap")) {
    ast* n = ast1->mid_l->right;
    ast* y = ast1->right->left->left->right->left;
    ast* x = ast1->right->left->right->right->left->left->left;

    result = ast_new_operation(AST_ARG, ast_new_number(1), 0);
    result = ast_new_operation(AST_ARG, y, result);
    result = ast_new_operation(AST_ARG, ast_new_number(1), result);
    result = ast_new_operation(AST_ARG, x, result);
    result = ast_new_operation(AST_ARG, n, result);
    result = ast_new_operation(AST_CALL, ast_new_id("sswap"), result);
    result = ast_new_operation(AST_EXPST, result, 0);
  }

  if(!strcmp(ast2->left->id, "sgemv")) {
    ast* beta;
    ast* m  = ast1->mid_l->right;
    ast* y  = ast1->right->left->right->left->left->left;

    if(ast1->right->left->right->left->right->right->type == AST_ARRAY) {
    if(ast1->right->left->right->left->right->left->right->type == AST_ARRAY)
        beta = ast1->right->left->right->left->right->left->left;
      else
        beta = ast1->right->left->right->left->right->left->right;
    } else {
      if(ast1->right->left->right->left->right->right->left->type == AST_ARRAY)
        beta = ast1->right->left->right->left->right->right->right;
      else
        beta = ast1->right->left->right->left->right->right->left;
    }


    ast* alpha, *a, *x;
    ast* f2 = ast1->right->left->left;
    ast* n  = f2->mid_l->right;

    if(f2->right->left->left->right->right->type == AST_ARRAY) {
      if(f2->right->left->left->right->left->right->type == AST_ARRAY) {
        alpha = f2->right->left->left->right->left->left->left;
        a     = f2->right->left->left->right->left->left->right->left;
        x     = f2->right->left->left->right->left->right->left;
      } else {
        x     = f2->right->left->left->right->left->left->right->left;
        a     = f2->right->left->left->right->left->left->left->left;
        alpha = f2->right->left->left->right->left->right;
      }
    } else {
      if(f2->right->left->left->right->right->right->type == AST_ARRAY) {
        alpha = f2->right->left->left->right->right->left->left;
        a     = f2->right->left->left->right->right->left->right->left;
        x     = f2->right->left->left->right->right->right->left;
      } else {
        x     = f2->right->left->left->right->right->left->right->left;
        a     = f2->right->left->left->right->right->left->left->left;
        alpha = f2->right->left->left->right->right->right;
      }
    }

    result = ast_new_operation(AST_ARG, ast_new_number(1), 0);
    result = ast_new_operation(AST_ARG, y, result);
    result = ast_new_operation(AST_ARG, beta, result);
    result = ast_new_operation(AST_ARG, ast_new_number(1), result);
    result = ast_new_operation(AST_ARG, x, result);
    result = ast_new_operation(AST_ARG, m, result);
    result = ast_new_operation(AST_ARG, a, result);
    result = ast_new_operation(AST_ARG, alpha, result);
    result = ast_new_operation(AST_ARG, n, result);
    result = ast_new_operation(AST_ARG, m, result);
    result = ast_new_operation(AST_ARG, ast_new_number(78), result);
    result = ast_new_operation(AST_CALL, ast_new_id("sgemv"), result);
    result = ast_new_operation(AST_EXPST, result, 0);
  }

  if(!strcmp(ast2->left->id, "sgemm")) {
    ast* f2 = ast1->right->left;
    ast* f3 = f2->right->left->right;
    ast* l = ast1->mid_l->right;
    ast* n = f2->mid_l->right;
    ast* m = f3->mid_l->right;
    ast* c = f2->right->left->left->left->left->left;
    ast* beta = f2->right->left->left->left->right->left;
    ast* a = f3->right->left->left->right->right->left->right->left;
    ast* alpha = f3->right->left->left->right->right->left->left;
    ast* b = f3->right->left->left->right->right->right->left;

    result = ast_new_operation(AST_ARG, ast_new_number(1), 0);
    result = ast_new_operation(AST_ARG, c, result);
    result = ast_new_operation(AST_ARG, beta, result);
    result = ast_new_operation(AST_ARG, ast_new_number(1), result);
    result = ast_new_operation(AST_ARG, b, result);
    result = ast_new_operation(AST_ARG, ast_new_number(1), result);
    result = ast_new_operation(AST_ARG, a, result);
    result = ast_new_operation(AST_ARG, alpha, result);
    result = ast_new_operation(AST_ARG, m, result);
    result = ast_new_operation(AST_ARG, n, result);
    result = ast_new_operation(AST_ARG, l, result);
    result = ast_new_operation(AST_ARG, ast_new_number(78), result);
    result = ast_new_operation(AST_ARG, ast_new_number(78), result);
    result = ast_new_operation(AST_CALL, ast_new_id("sgemm"), result);
    result = ast_new_operation(AST_EXPST, result, 0);
  }

  return result;
}


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


bool are_identical(ast* ast1, ast* ast2)
{
    if(ast1 == NULL && ast2 == NULL)
    {
      return true;
    }
    if(ast1 == NULL || ast2 == NULL)
    {
      return false;
    }

    if((ast1->type == AST_ID || ast1->type == AST_NUMBER) && (ast2->type == AST_NUMBER || ast2->type == AST_ID))
     return 1;

    if(ast1->type == AST_FOR && ast2->type == AST_FOR)
    {
      return ( ast1->type == ast2->type
             && are_identical(ast1->left, ast2->left)
             && are_identical(ast1->mid_l, ast2->mid_l)
             && are_identical(ast1->mid_r, ast2->mid_r)
             && are_identical(ast1->right, ast2->right) );
    }
    else
    {
      return ( ast1->type == ast2->type && are_identical(ast1->left, ast2->left) && are_identical(ast1->right, ast2->right) );
    }
}
