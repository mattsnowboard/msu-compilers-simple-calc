#ifndef _EXPONENT_H
#define _EXPONENT_H

#include "Binary.h"
#include <cmath>

class Exponent : public Binary
{
public:
    Exponent(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    Exponent(Exponent& Source):Binary(Source._left, Source._right){}
    Exponent& operator=(Exponent& RHS){return *this;}
    
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
