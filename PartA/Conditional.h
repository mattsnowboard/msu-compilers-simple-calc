#ifndef _CONDITIONAL_H
#define _CONDITIONAL_H

#include "Statement.h"
#include "StatementList.h"
#include <list>

class Conditional : public Statement
{
public:
    Conditional(Numerical *cond, StatementList *stmts) :
        _cond(cond), _stmts(stmts)
    {}
    virtual ~Conditional() {}

protected:
    Numerical *_cond;
    StatementList *_stmts;
};

#endif
