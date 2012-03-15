#ifndef _WHILESTMT_H
#define _WHILESTMT_H

#include "Conditional.h"

class WhileStmt : public Conditional
{
public:
    WhileStmt(Statements *left, Statements *right) :
        Conditional(left, right) {}

    virtual void Evaluate()
    {
       	if (_left && _right)
	{
        }
    }
};

#endif
