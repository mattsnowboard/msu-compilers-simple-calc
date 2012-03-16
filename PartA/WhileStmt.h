#ifndef _WHILESTMT_H
#define _WHILESTMT_H

#include "Conditional.h"

class WhileStmt : public Conditional
{
public:
    WhileStmt(Numerical *cond, StatementList *stmts) :
        Conditional(cond, stmts)
    {}

    virtual void Evaluate()
    {
        if (_cond)
        {
            _cond->Evaluate();
       	    while (_cond->Get() != 0) {
                // true, execute statement list
                // hopefully this is not an infinite loop, we could implment
                // a way to break out after a very large number of iterations
                _stmts->Execute();
            }
        }
    }

    virtual WhileStatement* Clone()
    {
        Numerical *c = (_cond) ? _cond->Clone() : NULL;
        StatementList *s = (_stmts) ? _stmts->Clone() : NULL;
        WhileStmt *wstmt = new WhileStmt(c, s);
        return wstmt;
    }

};

#endif
