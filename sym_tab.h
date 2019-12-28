#ifndef __SYM_TAB_H__
#define __SYM_TAB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#define MAX_STR 42
typedef enum sym_type { INT_S, FUNC, TAB_INT } sym_type;
typedef enum OPs { INCR_VAL, DECR_VAL, AS_VAL } OPs;


typedef struct sym_tab 
{
    sym_type type;
	char *id;
	int is_const; //1 true 0 false
	int is_set; //1 true 0 false
	int i_val; //-1 default val
	union {
		char *args;
		int *i_tab;
	};
	struct sym_tab *next;
} sym_tab;


sym_tab* new_node();
sym_tab* new_node_tab();
sym_tab* new_node_func();
sym_tab* sym_search(sym_tab*, char*);
void sym_add(sym_type, sym_tab **, char *, int, int);
void sym_free(sym_tab *);
void sym_print(sym_tab *);
void sym_mod(sym_tab **, char*, OPs, int);


#endif