#include "sym_tab.h"

#define MAX_STR 26

// Add New symbol 
sym_tab* sym_add(sym_type type, sym_tab* tab, char *name)
{
	if (tab == NULL)
	{
		tab = malloc(sizeof(struct sym_tab));
        tab->type = type;
		tab->id = strdup(name);
		return tab;
	}
	else
	{
		sym_tab *parse = tab;
		while (parse->next != NULL)
			parse = parse->next;
		parse->next = malloc(sizeof(struct sym_tab));
		parse->next->id = strdup(name);
		return parse->next;
	}
}

// New temp
sym_tab* sym_new(sym_tab* table)
{
	static int temporary_number = 0;
	char temporary_name[MAX_STR];
	snprintf(temporary_name, MAX_STR, "temp%d", temporary_number);
	temporary_number++;
	return sym_add(INT ,table, temporary_name);
}

sym_tab* sym_search(sym_tab *tab, char *name)
{
	while (tab != NULL)
	{
		if (strcmp(tab->id, name) == 0)
			return tab;
		tab = tab->next;
	}
	return NULL;
}

void sym_free(sym_tab *tab)
{
    while(tab != NULL)
    {
        free(tab->id);
        switch (tab->type) 
        {
            case FUNC:
                free(tab->args);
                break;
            case TAB_INT:
                free(tab->i_tab);
                break;
            case TAB_FLOAT:
                free(tab->f_tab);
                break;
            default:
                break;
        }
        tab = tab->next;
    }
}

void symbol_print(sym_tab *tab)
{
	while (tab != NULL)
	{
		printf("id : %10s : ", tab->id);
        printf("type : %u : ", tab->type);
		(tab->is_set) ? printf("is_set") : printf("is not set");
        (tab->is_const) ? printf("is const") : printf("is not const");
		switch(tab->type){
            case INT:
                printf("val = %d", tab->i_val);
                break;
            case FLOAT:
                printf("val = %f", tab->f_val);
                break;
            case FUNC:
                printf("args = %s", tab->args);
                break;
            case TAB_INT:
                printf("int tab");
                break;
            case TAB_FLOAT:
                printf("float tab");
        }
		tab = tab->next;
	}
}