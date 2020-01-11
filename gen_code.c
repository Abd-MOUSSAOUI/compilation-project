#include "gen_code.h"

void gencode(ast* ast, sym_tab* tab)
{
    sym_tab* tmp = NULL;
    switch(ast->type)
    {
        case AST_ID:
            printf("%s", ast->id);
            break;
        case AST_NUMBER:
            printf("%d", ast->number);
            break;
        case AST_CONST:
            printf("const ");
            gencode(ast->op.left,tab);
            break;
        case AST_DIM:
            printf("[");
            if(ast->op.left)
              gencode(ast->op.left,tab);
            printf("]");
            if(ast->op.right)
              gencode(ast->op.right,tab);
            break;
        case AST_ARR_ARG:
            gencode(ast->op.left,tab);
            if(ast->op.right) {
              printf(" ,");
              gencode(ast->op.right,tab);
            }
            break;
        case AST_ARRAY:
            gencode(ast->op.left,tab);
            if(ast->op.right) {
              gencode(ast->op.right,tab);
            } else {
              printf("[]");
            }
            break;
        case AST_ASIGN:
            gencode(ast->op.left,tab);
            printf(" = ");
            gencode(ast->op.right,tab);
            break;
        case AST_NEG:
            printf("-");
            gencode(ast->op.left,tab);
            break;
        case AST_INCR:
            gencode(ast->op.left,tab);
            printf("++");
            break;
        case AST_DECR:
            gencode(ast->op.left,tab);
            printf("--");
            break;
        case AST_NOT:
            printf("!");
            gencode(ast->op.left,tab);
            break;
        case AST_EQ:
            gencode(ast->op.left,tab);
            printf(" == ");
            gencode(ast->op.right,tab);
            break;
        case AST_NEQ:
            gencode(ast->op.left,tab);
            printf(" != ");
            gencode(ast->op.right,tab);
            break;
        case AST_GT:
            gencode(ast->op.left,tab);
            printf(" > ");
            gencode(ast->op.right,tab);
            break;
        case AST_GE:
            gencode(ast->op.left,tab);
            printf(" >= ");
            gencode(ast->op.right,tab);
            break;
        case AST_LT:
            gencode(ast->op.left,tab);
            printf(" < ");
            gencode(ast->op.right,tab);
            break;
        case AST_LE:
            gencode(ast->op.left,tab);
            printf(" <= ");
            gencode(ast->op.right,tab);
            break;
        case AST_OR:
            gencode(ast->op.left,tab);
            printf(" || ");
            gencode(ast->op.right,tab);
            break;
        case AST_AND:
            gencode(ast->op.left,tab);
            printf(" && ");
            gencode(ast->op.right,tab);
            break;
        case AST_ADD:
            gencode(ast->op.left,tab);
            printf(" + ");
            gencode(ast->op.right,tab);
            break;
        case AST_MIN:
            gencode(ast->op.left,tab);
            printf(" - ");
            gencode(ast->op.right,tab);
            break;
        case AST_MUL:
            gencode(ast->op.left,tab);
            printf(" * ");
            gencode(ast->op.right,tab);
            break;
        case AST_DIV:
            gencode(ast->op.left,tab);
            printf(" / ");
            gencode(ast->op.right,tab);
            break;
        case AST_DECL:
            printf("int ");
            gencode(ast->op.left,tab);
            if(ast->op.right)
            {
                printf(" = ");
                gencode(ast->op.right,tab);
            }
            printf(";\n");
            break;
        case AST_ARR_DECL:
            printf("int ");
            gencode(ast->op.left,tab);
            if(ast->op.mid_l) {
              gencode(ast->op.mid_l,tab);
            } else {
              printf("[]");
            }
            if(ast->op.mid_r) {
              printf(" = {");
              gencode(ast->op.mid_r,tab);
              printf("}");
            }
            printf(";\n");
            break;
        case AST_ARG:
            gencode(ast->op.left,tab);
            if(ast->op.right)
            {
                printf(", ");
                gencode(ast->op.right,tab);
            }
            break;
        case AST_PARAML:
            if(ast->op.left->type != AST_PARAML)
              printf("int ");
            gencode(ast->op.left,tab);
            if(ast->op.right)
            {
                printf(", ");
                if(ast->op.right->type == AST_ID)
                    printf("int ");
                gencode(ast->op.right,tab);
            }
            break;
        case AST_STMTL:
            gencode(ast->op.left,tab);
            if(ast->op.right)
                gencode(ast->op.right,tab);
            break;
        case AST_BLOCK:
            printf("\n{\n");
            if(ast->op.left)
                gencode(ast->op.left,tab);
            printf("}\n");
            break;
        case AST_FUNC:
            tmp = sym_search(tab, FUNC, ast->op.left->id, 0);
            if(tmp->r_type == 0)
                printf("int ");
            if(tmp->r_type == 1)
                printf("void ");
            gencode(ast->op.left,tab);
            printf("(");
            if(ast->op.mid_l)
              gencode(ast->op.mid_l,tab);
            printf(") ");
            gencode(ast->op.mid_r,tab);
            printf("\n");

            break;
        case AST_EXPST:
            if(ast->op.left) {
                gencode(ast->op.left,tab);
                printf(";\n");
            }
            break;
        case AST_RET:
            printf("return ");
            if(ast->op.left)
                gencode(ast->op.left,tab);
            printf(";\n");
            break;
        case AST_CALL:
            gencode(ast->op.left,tab);
            printf("(");
            if(ast->op.right)
                gencode(ast->op.right,tab);
            printf(")");
            break;
        case AST_IF:
            printf("if (");
            gencode(ast->op.left,tab);
            printf(")\n");
            gencode(ast->op.mid_l,tab);
            break;
        case AST_IF_ELSE:
            printf("if (");
            gencode(ast->op.left,tab);
            printf(")");
            gencode(ast->op.mid_l,tab);
            printf(" else ");
            gencode(ast->op.mid_r,tab);
            break;
        case AST_FOR:
            printf("for (");
            gencode(ast->op.left,tab);
            printf(";");
            gencode(ast->op.mid_l,tab);
            printf(";");
            gencode(ast->op.mid_r,tab);
            printf(")");
            gencode(ast->op.right,tab);
            break;
        case AST_WHILE:
            printf("while (");
            gencode(ast->op.left,tab);
            printf(")");
            gencode(ast->op.right,tab);
            break;
        case AST_PRINTF:
            printf("printf (");
            gencode(ast->op.left,tab);
            printf(");\n");
            break;
        case AST_PROG:
            gencode(ast->op.left,tab);
            if(ast->op.right)
                gencode(ast->op.right,tab);
            break;
  };
}
