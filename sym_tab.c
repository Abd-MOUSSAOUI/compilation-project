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
  tab->args = 0;
  tab->next = NULL;
  return tab;
}

sym_tab* new_node_tab() {
  sym_tab* tab = malloc(sizeof(sym_tab));
  tab->id = NULL;
  tab->is_const = 0;
  tab->is_set = 0;
  tab->dim = 0;
  tab->next = NULL;
  return tab;
}

sym_tab* sym_search(sym_tab* tab,sym_type type, char* id)
{
    while (tab != NULL)
    {
        if(type == TAB_INT || type == INT_V)
        {
            if (strcmp(tab->id, id) == 0 && tab->type != INT_F)
                {
                    return tab;
                }
        }
        if(type == INT_F || type == FUNC)
        {
            if((strcmp(tab->id, id) == 0) && tab->type == type)
            return tab;
        }
        tab = tab->next;
    }
    return NULL;
}

void sym_add_var(sym_type type, sym_tab **tab, char *name, int val, int is_const)
{
    sym_tab* new = new_node();
    new->id = strdup(name);
    new->type = type;
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

void sym_add_func(sym_type type, retour_type r_type, sym_tab **tab, char *name, int nb_args, int is_const)
{
    sym_tab* new = new_node_func();
    new->id = strdup(name);
    new->type = type;
    new->r_type = r_type;
    new->args = nb_args;
    new->is_set = 1;
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

void sym_add_tab(sym_type type, sym_tab **tab, char *name, int dim, int is_const)
{
    sym_tab* new = new_node_tab();
    new->id = strdup(name);
    new->type = type;
    new->dim = dim;
    new->is_set = 0;
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


int check_args_nbr(sym_tab *tab, char*id, int nbr)
{
    while (tab != NULL)
  {
    if (strcmp(tab->id, id) == 0 && tab->type == FUNC)
    {
        if(tab->args == nbr)
            return 1;
    }
    tab = tab->next;
  }
  return 0;
}

void sym_mod(sym_tab **tab, char* name, OPs op, int a)
{
    sym_tab* last = *tab;
    while (last != NULL)
	{
		if (strcmp(last->id, name) == 0)
        {
            if(((last->type == INT_V) || (last->type == INT_F)) && (last->is_const == 0))
            {
                if(op == AS_VAL)
                {
                    last->i_val = a;
                    last->is_set = 1;
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
        tab = tab->next;
    }
}

void sym_print(sym_tab *tab)
{
	while (tab != NULL)
	{
		printf("id: %s\t", tab->id);
        (tab->is_const) ? printf("is const\t") : printf("");
		switch(tab->type){
            case INT_V:
                printf("type: int\t");
                if(tab->is_set)
                    printf("val = %d\n", tab->i_val);
                else
                    printf("val = N/O\n");
                break;
            case FUNC:
                printf("type : function\t return type: int\t");
                printf("nb args = %d\n", tab->args);
                break;
            case TAB_INT:
                printf("type : tab of int\t");
                printf("nb of dim = %d\n", tab->dim);
                break;
            case INT_F:
                printf("type: arg of type: int\n");
                break;
            default:
            break;
        }
		tab = tab->next;
	}
}
