#ifndef _EXPONENT_H
#define _EXPONENT_H

#include "Binary.h"
#include <cmath>

class Exponent : public Binary
{
public:
    Exponent(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual Exponent* Clone()
    {
        Numerical *l = (_left) ? _left->Clone() : NULL;
        Numerical *r = (_right) ? _right->Clone() : NULL;
        Exponent *b = new Exponent(l, r);
        return b;
    }

    virtual void Evaluate()
    {
        if (_left && _right) {
            _left->Evaluate();
            _right->Evaluate();
            _value = std::pow(_left->Get(), _right->Get());
            _isEvaluated = true;
        }
    }
};

#endif
