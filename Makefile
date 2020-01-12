prefixe=blaster

all: $(prefixe).y $(prefixe).l ast.c ast.h print_tree.c print_tree.h sym_tab.c sym_tab.h gen_code.c gen_code.h ast_optim.h ast_optim.c
	yacc -d $(prefixe).y
	lex $(prefixe).l
	gcc -o $(prefixe) y.tab.c lex.yy.c ast.c print_tree.c sym_tab.c gen_code.c ast_optim.c -ly

test:
	@for i in Tests/*.c; do \
			./blaster $$i blast.c \
			&& printf "%s""$$i \033[0;32m PASSED \033[0m "\
			|| printf "%s""$$i \031[0;32m FAILED \033[0m " ; \
			printf "\n\n"; \
	done

clean:
	rm -rf .vscode y.tab.c y.tab.h lex.yy.c blaster
