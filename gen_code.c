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
            gencode(ast->left,tab);
            break;
        case AST_DIM:
            printf("[");
            if(ast->left)
              gencode(ast->left,tab);
            printf("]");
            if(ast->right)
              gencode(ast->right,tab);
            break;
        case AST_ARR_ARG:
            gencode(ast->left,tab);
            if(ast->right) {
              printf(" ,");
              gencode(ast->right,tab);
            }
            break;
        case AST_ARRAY:
            gencode(ast->left,tab);
            if(ast->right) {
              gencode(ast->right,tab);
            } else {
              printf("[]");
            }
            break;
        case AST_ASIGN:
            gencode(ast->left,tab);
            printf(" = ");
            gencode(ast->right,tab);
            break;
        case AST_NEG:
            printf("-");
            gencode(ast->left,tab);
            break;
        case AST_INCR:
            gencode(ast->left,tab);
            printf("++");
            break;
        case AST_DECR:
            gencode(ast->left,tab);
            printf("--");
            break;
        case AST_NOT:
            printf("!");
            gencode(ast->left,tab);
            break;
        case AST_EQ:
            gencode(ast->left,tab);
            printf(" == ");
            gencode(ast->right,tab);
            break;
        case AST_NEQ:
            gencode(ast->left,tab);
            printf(" != ");
            gencode(ast->right,tab);
            break;
        case AST_GT:
            gencode(ast->left,tab);
            printf(" > ");
            gencode(ast->right,tab);
            break;
        case AST_GE:
            gencode(ast->left,tab);
            printf(" >= ");
            gencode(ast->right,tab);
            break;
        case AST_LT:
            gencode(ast->left,tab);
            printf(" < ");
            gencode(ast->right,tab);
            break;
        case AST_LE:
            gencode(ast->left,tab);
            printf(" <= ");
            gencode(ast->right,tab);
            break;
        case AST_OR:
            gencode(ast->left,tab);
            printf(" || ");
            gencode(ast->right,tab);
            break;
        case AST_AND:
            gencode(ast->left,tab);
            printf(" && ");
            gencode(ast->right,tab);
            break;
        case AST_ADD:
            gencode(ast->left,tab);
            printf(" + ");
            gencode(ast->right,tab);
            break;
        case AST_MIN:
            gencode(ast->left,tab);
            printf(" - ");
            gencode(ast->right,tab);
            break;
        case AST_MUL:
            gencode(ast->left,tab);
            printf(" * ");
            gencode(ast->right,tab);
            break;
        case AST_DIV:
            gencode(ast->left,tab);
            printf(" / ");
            gencode(ast->right,tab);
            break;
        case AST_DECL:
            printf("int ");
            gencode(ast->left,tab);
            if(ast->right)
            {
                printf(" = ");
                gencode(ast->right,tab);
            }
            printf(";\n");
            break;
        case AST_ARR_DECL:
            printf("int ");
            gencode(ast->left,tab);
            if(ast->mid_l) {
              gencode(ast->mid_l,tab);
            } else {
              printf("[]");
            }
            if(ast->mid_r) {
              printf(" = {");
              gencode(ast->mid_r,tab);
              printf("}");
            }
            printf(";\n");
            break;
        case AST_ARG:
            gencode(ast->left,tab);
            if(ast->right)
            {
                printf(", ");
                gencode(ast->right,tab);
            }
            break;
        case AST_PARAML:
            if(ast->left->type != AST_PARAML)
              printf("int ");
            gencode(ast->left,tab);
            if(ast->right)
            {
                printf(", ");
                if(ast->right->type == AST_ID)
                    printf("int ");
                gencode(ast->right,tab);
            }
            break;
        case AST_STMTL:
            gencode(ast->left,tab);
            if(ast->right)
                gencode(ast->right,tab);
            break;
        case AST_BLOCK:
            printf("\n{\n");
            if(ast->left)
                gencode(ast->left,tab);
            printf("}\n");
            break;
        case AST_FUNC:
            tmp = sym_search(tab, FUNC, ast->left->id, 0);
            if(tmp->r_type == 0)
                printf("int ");
            if(tmp->r_type == 1)
                printf("void ");
            gencode(ast->left,tab);
            printf("(");
            if(ast->mid_l)
              gencode(ast->mid_l,tab);
            printf(") ");
            gencode(ast->mid_r,tab);
            printf("\n");

            break;
        case AST_EXPST:
            if(ast->left) {
                gencode(ast->left,tab);
                printf(";\n");
            }
            break;
        case AST_RET:
            printf("return ");
            if(ast->left)
                gencode(ast->left,tab);
            printf(";\n");
            break;
        case AST_CALL:
            gencode(ast->left,tab);
            printf("(");
            if(ast->right)
                gencode(ast->right,tab);
            printf(")");
            break;
        case AST_IF:
            printf("if (");
            gencode(ast->left,tab);
            printf(")\n");
            gencode(ast->mid_l,tab);
            break;
        case AST_IF_ELSE:
            printf("if (");
            gencode(ast->left,tab);
            printf(")");
            gencode(ast->mid_l,tab);
            printf(" else ");
            gencode(ast->mid_r,tab);
            break;
        case AST_FOR:
            printf("for (");
            gencode(ast->left,tab);
            printf(";");
            gencode(ast->mid_l,tab);
            printf(";");
            gencode(ast->mid_r,tab);
            printf(")");
            gencode(ast->right,tab);
            break;
        case AST_WHILE:
            printf("while (");
            gencode(ast->left,tab);
            printf(")");
            gencode(ast->right,tab);
            break;
        case AST_PRINTF:
            printf("printf (");
            gencode(ast->left,tab);
            printf(");\n");
            break;
        case AST_DEF:
            printf("#define ");
            gencode(ast->left,tab);
            if(ast->right) {
              printf(" ");
              gencode(ast->right,tab);
            }
            printf("\n");
            break;
        case AST_INCL:
            printf("#include ");
            gencode(ast->left,tab);
            printf("\n");
            break;
        case AST_PROG:
            gencode(ast->left,tab);
            if(ast->right)
                gencode(ast->right,tab);
            break;
  };
}
