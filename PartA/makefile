CXXFLAGS = -Wall -std=c++0x

all: simplecalc

simplecalc:	expression.o y.tab.o lex.yy.o Numerical.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o simplecalc

lex.yy.c: expression.l y.tab.h
	flex expression.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h: expression.y
	bison --yacc --defines expression.y

y.tab.o: y.tab.c y.tab.h
	gcc -c y.tab.c

expression.o: expression.cpp y.tab.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c expression.cpp

Numerical.o: Numerical.h Numerical.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Numerical.cpp

clean: 
	rm simplecalc *.o y.* lex.*
