#include "gen_code.h"

void gencode(ast* ast)
{
    switch(ast->type) 
    {
        case AST_ID:
            printf("%s", ast->id);
            break;
        case AST_NUMBER:
            printf("%d ", ast->number);
            break;
        case AST_ASIGN:
            gencode(ast->op.left);
            printf(" = ");
            gencode(ast->op.right);
            printf(";");
            break;
        case AST_NEG:
            printf("-");
            gencode(ast->op.left);
            break;
        case AST_INCR:
            gencode(ast->op.left);
            printf("++");
            break;
        case AST_DECR:
            gencode(ast->op.left);
            printf("-- ");
            break;
        case AST_EQ:
            gencode(ast->op.left);
            printf("== ");
            gencode(ast->op.right);
            break;
        case AST_NEQ:
            gencode(ast->op.left);
            printf("!= ");
            gencode(ast->op.right);
            break;
        case AST_GT:
            gencode(ast->op.left);
            printf(" > ");
            gencode(ast->op.right);
            break;
        case AST_GE:
            gencode(ast->op.left);
            printf(" >= ");
            gencode(ast->op.right);
            break;
        case AST_LT:
            gencode(ast->op.left);
            printf(" < ");
            gencode(ast->op.right);
            break;
        case AST_LE:
            gencode(ast->op.left);
            printf(" <= ");
            gencode(ast->op.right);
            break;
        case AST_ADD:
            gencode(ast->op.left);
            printf(" + ");
            gencode(ast->op.right);
            break;
        case AST_MIN:
            gencode(ast->op.left);
            printf(" - ");
            gencode(ast->op.right);
            break;
        case AST_MUL:
            gencode(ast->op.left);
            printf(" * ");
            gencode(ast->op.right);
            break;
        case AST_DIV:
            gencode(ast->op.left);
            printf(" / ");
            gencode(ast->op.right);
            break;
        case AST_DECL:
            printf("int ");
            gencode(ast->op.left);
            if(ast->op.right != NULL)
            {
                printf("= ");
                gencode(ast->op.right);
            }
            printf(";\n");
            break;
        case AST_STMT:
            gencode(ast->op.left);
            if(ast->op.right != NULL)
            {
                gencode(ast->op.right);
            }
            else
                printf("\n");
            break;
        case AST_BLOCK:
            printf(" {\n");
            if(ast->op.left != NULL)
            {
                printf(" ");
                gencode(ast->op.left);
            } 
            printf("\n }\n");
            break;
        case AST_FUNC:
            printf("int ");
            gencode(ast->op.left);
            printf("()");
            gencode(ast->op.right);
            break;
        case AST_RET:
            printf(" return ");
            if(ast->op.left != NULL)
                gencode(ast->op.left);
            printf(";");
            break;
        case AST_IF:
            printf("if (");
            gencode(ast->op.left);
            printf(")\n");
            gencode(ast->op.mid_l);
            printf("\n");
            break;
        case AST_IF_ELSE:
            printf("if (");
            gencode(ast->op.left);
            printf(")\n");
            gencode(ast->op.mid_l);
            printf(" else \n");
            gencode(ast->op.mid_r);
            printf("\n");
            break;
        case AST_FOR:
            printf("for (");
            gencode(ast->op.left);
            gencode(ast->op.mid_l);
            printf(";");
            gencode(ast->op.mid_r);
            printf(")\n");
            gencode(ast->op.right);
            break;
        case AST_WHILE:
            printf(" while (");
            gencode(ast->op.left);
            printf(")\n");
            gencode(ast->op.right);
            break;

  };
}
