#ifndef _DIVIDE_H
#define _DIVIDE_H

#include "Binary.h"

class Divide : public Binary
{
public:
    Divide(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual Divide* Clone()
    {
        Numerical *l = (_left) ? _left->Clone() : NULL;
        Numerical *r = (_right) ? _right->Clone() : NULL;
        Divide *b = new Divide(l, r);
        return b;
    }

    virtual void Evaluate()
    {
        if (_left && _right) {
            _left->Evaluate();
            _right->Evaluate();
            // Don't care about divide by zero??
            _value = _left->Get() / _right->Get();
            _isEvaluated = true;
        }
    }
};

#endif
