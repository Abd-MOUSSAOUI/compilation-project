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

int ast_compare(ast* src_ast, ast* blst) {

  if(src_ast->type != blst->type)
    return 1;

  if( (src_ast->op.left == 0 && blst->op.left != 0) || (src_ast->op.right == 0 && blst->op.right != 0) ||
      (src_ast->op.mid_l == 0 && blst->op.mid_l != 0) || (src_ast->op.mid_r == 0 && blst->op.mid_r != 0) )
        return 1;

  if( (src_ast->op.left != 0 && blst->op.left == 0) || (src_ast->op.right != 0 && blst->op.right == 0) ||
      (src_ast->op.mid_l != 0 && blst->op.mid_l == 0) || (src_ast->op.mid_r != 0 && blst->op.mid_r == 0) )
        return 1;
         
  // if( (src_ast->op.left->type != blst->op.left->type) || (src_ast->op.mid_l->type != blst->op.mid_l->type) ||
  //     (src_ast->op.mid_r->type != blst->op.mid_r->type) || (src_ast->op.right->type != blst->op.right->type) )
  //       return 1;

  if( !src_ast->op.left || !src_ast->op.mid_l || !src_ast->op.mid_r || !src_ast->op.right)
    return 0;

  return ast_compare(src_ast->op.left, blst->op.left) + ast_compare(src_ast->op.mid_l, blst->op.mid_l) +
         ast_compare(src_ast->op.mid_r, blst->op.mid_r) + ast_compare(src_ast->op.right, blst->op.right);
}
