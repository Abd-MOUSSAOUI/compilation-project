#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ast* ast_new_fornary(ast_type type, ast* left, ast* mid_l, ast* mid_r, ast* right) {
  ast* new = malloc(sizeof(ast));
  new->type = type;
  new->op.left = left;
  new->op.mid_l = mid_l;
  new->op.mid_r = mid_r;
  new->op.right = right;
  return new;
}

ast* ast_new_trenary(ast_type type, ast* left, ast* mid_l, ast* mid_r) {
  ast* new = malloc(sizeof(ast));
  new->type = type;
  new->op.left = left;
  new->op.mid_l = mid_l;
  new->op.mid_r = mid_r;
  return new;
}

ast* ast_new_operation(ast_type type, ast* left, ast* right) {
  ast* new = malloc(sizeof(ast));
  new->type = type;
  new->op.left = left;
  new->op.right = right;
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
  if(!ast)
    return;

  switch (ast->type) {
      case AST_NUMBER:
        break;
      case AST_ID:
        free(ast->id);
        break;
      case AST_ARRAY:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_DIM:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_PARAML:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_FOR:
        ast_free(ast->op.left);
        ast_free(ast->op.mid_l);
        ast_free(ast->op.mid_r);
        ast_free(ast->op.right);
        break;
      case AST_WHILE:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_PROG:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_IF_ELSE:
        ast_free(ast->op.left);
        ast_free(ast->op.mid_l);
        ast_free(ast->op.mid_r);
        break;
      case AST_IF:
        ast_free(ast->op.left);
        ast_free(ast->op.mid_l);
        break;
      case AST_ASIGN:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_FUNC:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_ARG:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_CALL:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_STMTL:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_EXPST:
        ast_free(ast->op.left);
        break;
      case AST_RET:
        ast_free(ast->op.left);
        break;
      case AST_DECL:
        ast_free(ast->op.right);
        ast_free(ast->op.left);
        break;
      case AST_BLOCK:
        ast_free(ast->op.left);
        break;
      case AST_NEG:
        ast_free(ast->op.left);
        break;
      case AST_INCR:
        ast_free(ast->op.left);
        break;
      case AST_DECR:
        ast_free(ast->op.left);
        break;
      case AST_EQ:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_NEQ:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_GT:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_GE:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_LT:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_LE:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_OR:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_AND:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_NOT:
        ast_free(ast->op.left);
        break;
      case AST_ADD:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_MIN:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_MUL:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
      case AST_DIV:
        ast_free(ast->op.left);
        ast_free(ast->op.right);
        break;
    }
}

void ast_print(ast* ast, int indent) {
  if(!ast)
    return;

  for (int i = 0; i < indent; i++)
    printf("    ");
  switch(ast->type) {
    case AST_ID:
      printf("ID (%s)\n", ast->id);
      break;
    case AST_NUMBER:
      printf("NUMBER (%d)\n", ast->number);
      break;
    case AST_ARRAY:
      printf("ARRAY_ACCESS\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_DIM:
      printf("DIM\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_PARAML:
      printf("PARAM_L\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_PROG:
      printf("PROG\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_ASIGN:
      printf("=\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_STMTL:
      printf("STMT\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_EXPST:
      printf("EXPST\n");
      ast_print(ast->op.left, indent + 1);
      break;
    case AST_RET:
      printf("RET\n");
      ast_print(ast->op.left, indent + 1);
      break;
    case AST_DECL:
      printf("DECL\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_BLOCK:
      printf("BLOCK\n");
      ast_print(ast->op.left, indent + 1);
      break;
    case AST_FUNC:
      printf("FUNC\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_CALL:
      printf("CALL\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_ARG:
      printf("CALL\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_NEG:
      printf("-(UN)\n");
      ast_print(ast->op.left, indent + 1);
      break;
    case AST_FOR:
      printf("FOR\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.mid_l, indent + 1);
      ast_print(ast->op.mid_r, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_WHILE:
      printf("WHILE\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_IF_ELSE:
      printf("IF_ELSE\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.mid_l, indent + 1);
      ast_print(ast->op.mid_r, indent + 1);
      break;
    case AST_IF:
      printf("IF\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.mid_l, indent + 1);
      break;
    case AST_INCR:
      printf("++\n");
      ast_print(ast->op.left, indent + 1);
      break;
    case AST_DECR:
      printf("--\n");
      ast_print(ast->op.left, indent + 1);
      break;
    case AST_NOT:
      printf("!\n");
      ast_print(ast->op.left, indent + 1);
      break;
    case AST_EQ:
      printf("==\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_NEQ:
      printf("!=\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_GT:
      printf(">\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_GE:
      printf(">=\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_LT:
      printf("<\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_LE:
      printf("<=\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_OR:
      printf("||\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_AND:
      printf("&&\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_ADD:
      printf("+\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_MIN:
      printf("-\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_MUL:
      printf("*\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
      break;
    case AST_DIV:
      printf("/\n");
      ast_print(ast->op.left, indent + 1);
      ast_print(ast->op.right, indent + 1);
  }
}
