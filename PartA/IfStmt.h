#ifndef _IFSTMT_H
#define _IFSTMT_H

#include "Conditional.h"

class IfStmt : public Conditional
{
public:
    IfStmt(Statements *left, Statements *right) :
        Conditional(left, right) {}

    virtual void Evaluate()
    {
       	if (_left && _right)
	{
            _left->Evaluate();
            _right->Evaluate();		
	//I think we need to call the greater than and less than tree here, I'm not quite sure what I need to do for that.
       	    if (_left < _right)
            	result = 1;
       	    else
            	result = 0;
            _isEvaluated = true;
        }
    }
};

#endif
