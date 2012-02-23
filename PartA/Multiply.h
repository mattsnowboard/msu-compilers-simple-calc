#ifndef _MULTIPLY_H
#define _MULTIPLY_H

#include "Binary.h"

class Multiply : public Binary
{
public:
    Multiply(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual void Evaluate()
    {
        if (_left && _right) {
            _value = _left->Get() * _right->Get();
        }
    }
};

#endif
