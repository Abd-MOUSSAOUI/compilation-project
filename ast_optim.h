#ifndef __AST_OPTIM_H__
#define __AST_OPTIM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ast* ast_divide(ast*);
int are_identical(ast *, ast*);
int is_subtree(ast*, ast*); 


#endif
