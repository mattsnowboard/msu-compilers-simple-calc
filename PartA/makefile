all: simplecalc

simplecalc:	expression.o y.tab.o lex.yy.o Node.o
	g++ expression.o y.tab.o Node.o lex.yy.o -o simplecalc

lex.yy.c: expression.l y.tab.h
	flex expression.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h: expression.y
	bison --yacc --defines expression.y

y.tab.o: y.tab.c y.tab.h
	gcc -c y.tab.c

expression.o: expression.cpp y.tab.h
	g++ -c expression.cpp

Node.o: Node.h Node.cpp
	g++ -c Node.cpp

clean: 
	rm simplecalc *.o y.* lex.*
