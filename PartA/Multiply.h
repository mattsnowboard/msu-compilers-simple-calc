#ifndef _MULTIPLY_H
#define _MULTIPLY_H

#include "Binary.h"

class Multiply : public Binary
{
public:
    Multiply(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual Multiply* Clone()
    {
        Numerical *l = (_left) ? _left->Clone() : NULL;
        Numerical *r = (_right) ? _right->Clone() : NULL;
        Multiply *b = new Multiply(l, r);
        return b;
    }

    virtual void Evaluate()
    {
        if (_left && _right) {
            _left->Evaluate();
            _right->Evaluate();
            _value = _left->Get() * _right->Get();
        }
    }
};

#endif
