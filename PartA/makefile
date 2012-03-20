
SRCS := Numerical.cpp function.cpp SymbolTable.cpp StrSymbolTable.cpp DotStatementVisitor.cpp
OBJS := $(SRCS:%.cpp=%.o)

CXXFLAGS = -Wall -g

DEPDIR = .deps
df = $(DEPDIR)/$(@F)

MAKEDEPEND = $(CXX) $(CPPFLAGS) -MM -o $(df).d $<

all: simplecalc

simplecalc:	$(OBJS) expression.o y.tab.o lex.yy.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o simplecalc

lex.yy.c: expression.l y.tab.h
	flex expression.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h: expression.y
	bison --yacc --defines expression.y --report=state

y.tab.o: y.tab.c y.tab.h
	gcc -c y.tab.c

expression.o: expression.cpp y.tab.h Expr.h DotStatementVisitor.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c expression.cpp

# dependency stuff
.D_TARGET:
	mkdir -p $(DEPDIR)
	touch $@

.PRECIOUS: .D_TARGET

# my other sources

%.o : %.cpp .D_TARGET
	$(MAKEDEPEND);
	@cp $(df).d $(df).P;
	@rm -f $(df).d
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

-include $(SRCS:%.cpp=$(DEPDIR)/%.o.P)

# clean

clean: 
	$(RM) $(OBJS) .D_TARGET expression.o simplecalc lex.yy.c lex.yy.o \
		y.tab.h y.tab.c y.tab.o \
	rm -rf $(DEPDIR)

# test
test: simplecalc
	./simplecalc < test1
	./simplecalc < test2
	./simplecalc < test3
	./simplecalc < test4
	./simplecalc < test5
	./simplecalc < test6
	./simplecalc < testif
	./simplecalc < teststats
	./simplecalc < testusercommand
	./simplecalc < testwhile
	./simplecalc < bottles_of_beer

