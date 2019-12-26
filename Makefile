prefixe=blaster

all: $(prefixe).y $(prefixe).l ast.c ast.h print_tree.c print_tree.h sym_tab.c sym_tab.h
	yacc -d $(prefixe).y
	lex $(prefixe).l
	gcc y.tab.c lex.yy.c ast.c print_tree.c sym_tab.c -ly

clean:
	rm *.o y.tab.c y.tab.h lex.yy.c a.out