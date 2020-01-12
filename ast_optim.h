#ifndef __AST_OPTIM_H__
#define __AST_OPTIM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"

ast* ast_divide(ast*);
bool are_identical(ast *, ast*);
ast* ast_first_for(ast*);
ast* ast_replace(ast* , ast*);
void optimizer(ast* , ast*);

#endif
