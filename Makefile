prefixe=blaster

all: $(prefixe).y $(prefixe).l ast.c ast.h print_tree.c print_tree.h sym_tab.c sym_tab.h gen_code.c gen_code.h ast_optim.h ast_optim.c
	yacc -d $(prefixe).y
	lex $(prefixe).l
	gcc y.tab.c lex.yy.c ast.c print_tree.c sym_tab.c gen_code.c ast_optim.c -ly

clean:
	rm -rf .vscode y.tab.c y.tab.h lex.yy.c a.out
