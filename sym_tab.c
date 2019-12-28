#include "sym_tab.h"


sym_tab* new_node() {
  sym_tab* tab = malloc(sizeof(sym_tab));
  tab->id = NULL;
  tab->is_const = 0;
  tab->is_set = 0;
  tab->i_val = -1;
  tab->next = NULL;
  return tab;
}

sym_tab* new_node_func() {
  sym_tab* tab = malloc(sizeof(sym_tab));
  tab->id = NULL;
  tab->is_const = 0;
  tab->is_set = 0;
  tab->i_val = -1;
  tab->args = NULL;
  tab->next = NULL;
  return tab;
}

sym_tab* new_node_tab() {
  sym_tab* tab = malloc(sizeof(sym_tab));
  tab->id = NULL;
  tab->is_const = 0;
  tab->is_set = 0;
  tab->i_val = -1;
  tab->i_tab = NULL;
  tab->next = NULL;
  return tab;
}

sym_tab* sym_search(sym_tab* tab, char* id) 
{
  while (tab != NULL) 
  {
    if (strcmp(tab->id, id) == 0)
      return tab;
    tab = tab->next;
  }
  return NULL;
}

void sym_add(sym_type type, sym_tab **tab, char *name, int val, int is_const) 
{
    sym_tab* new = new_node();
    new->id = strdup(name);

    if(val >= 0)
    {
        new->is_set = 1;
        new->i_val = val;
    }
    new->is_const = is_const;
    new->next = NULL;
    if (*tab == NULL)
	{
        *tab = new;
        return;
	}
	else
	{
        sym_tab* last = *tab;
		while(last->next != NULL)
		    last = last->next;
        last->next = new;
        return;
	}
}

void sym_mod(sym_tab **tab, char* name, OPs op, int a)
{
    sym_tab* last = *tab;
    while (last != NULL)
	{
		if (strcmp(last->id, name) == 0)
        {
            if((last->type == INT_S) && (last->is_const == 0))
            {
                if(op == AS_VAL)
                {
                    last->i_val = a;
                    return;
                }
                if(last->is_set == 1)
                {
                    if(op == INCR_VAL) 
                    {
                        last->i_val = last->i_val + a;
                        return;
                    } 
                    else if(op == DECR_VAL)
                    {
                        last->i_val = last->i_val - a;
                        return;
                    } 
                    else
                    {
                        fprintf(stderr, "ERROR: %s is not initialized\n", name);
                        exit(1);
                    }
                }
               
            }
            else
            {
                fprintf(stderr, "Error: %s is a const value !\n", name);
                exit(1);
            }
        }
		last = last->next;
	}
    fprintf(stderr, "ERROR: %s is not declared\n", name);
    exit(1);    
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
            default:
                break;
        }
        tab = tab->next;
    }
}

void sym_print(sym_tab *tab)
{
	while (tab != NULL)
	{
		printf("id: %s\t", tab->id);
        printf("type: INT\t");
        (tab->is_const) ? printf("is const\t") : printf("");
		switch(tab->type){
            case INT_S:
                printf("val = %d\n", tab->i_val);
                break;
            case FUNC:
                printf("args = %s\n", tab->args);
                break;
            case TAB_INT:
                printf("tab \n");
        }
		tab = tab->next;
	}
}