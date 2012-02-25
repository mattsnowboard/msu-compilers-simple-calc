#ifndef _GREATERTHAN_H
#define _GREATERTHAN_H

#include "Binary.h"

class GreaterThan : public Binary
{
public:
    GreaterThan(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    GreaterThan(GreaterThan& Source):Binary(Source._left, Source._right){}
    GreaterThan& operator=(GreaterThan& RHS){return *this;}
    
    virtual void Evaluate()
    {
        if (_left && _right) {
            _left->Evaluate();
            _right->Evaluate();
            _value = (_left->Get() > _right->Get()) ? 1 : 0;
            _isEvaluated = true;
        }
    }
};

#endif
