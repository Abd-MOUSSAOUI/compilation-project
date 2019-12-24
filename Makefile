prefixe=blaster

all: $(prefixe).y $(prefixe).l ast.c ast.h
	yacc -d $(prefixe).y
	lex $(prefixe).l
	gcc y.tab.c lex.yy.c ast.c -ly -lfl

clean:
	rm *.o y.tab.c y.tab.h lex.yy.c a.out
