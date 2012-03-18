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
    virtual ~Conditional()
    {
        if (_cond) {
            delete _cond;
            _cond = NULL;
        }
        if (_stmts) {
            delete _stmts;
            _stmts = NULL;
        }
    }

    Numerical const* GetCondition() const {
        return _cond;
    }

    StatementList const* GetStatements() const {
        return _stmts;
    }

protected:
    Numerical *_cond;
    StatementList *_stmts;
};

#endif
