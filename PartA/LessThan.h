#ifndef _LESSTHAN_H
#define _LESSTHAN_H

#include "Binary.h"

class LessThan : public Binary
{
public:
    LessThan(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    LessThan(LessThan& Source):Binary(Source._left, Source._right){}
    LessThan& operator=(LessThan& RHS){return *this;}

    virtual void Evaluate()
    {
        if (_left && _right) {
            _left->Evaluate();
            _right->Evaluate();
            _value = (_left->Get() < _right->Get()) ? 1 : 0;
            _isEvaluated = true;
        }
    }
};

#endif
