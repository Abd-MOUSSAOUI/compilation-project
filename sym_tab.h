#ifndef __SYM_TAB_H__
#define __SYM_TAB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sym_type { INT, FLOAT, FUNC, TAB_INT, TAB_FLOAT } sym_type;


typedef struct sym_tab 
{
    sym_type type;
	char *id;
	int is_const; //1 true 0 false
	int is_set; //1 true 0 false
	union {
		int i_val; float f_val;
		char *args;
		int *i_tab; float *f_tab;
	};
	struct sym_tab *next;
} sym_tab;

// fonctions de manipulation de la table des symboles
sym_tab* sym_new(sym_tab *);
sym_tab* sym_search(sym_tab *, char *);
sym_tab* sym_add(sym_type, sym_tab *, char *);
void sym_free(sym_tab *);
void sym_print(sym_tab *);

#endif