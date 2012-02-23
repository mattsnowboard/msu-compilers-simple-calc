#ifndef _EXPONENT_H
#define _EXPONENT_H

#include "Binary.h"
#include <cmath>

class Exponent : public Binary
{
public:
    Exponent(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual void Evaluate()
    {
        if (_left && _right) {
            _value = std::pow(_left->Get(), _right->Get());
        }
    }
};

#endif
