#ifndef _SUBTRACT_H
#define _SUBTRACT_H

#include "Binary.h"

class Subtract : public Binary
{
public:
    Subtract(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual void Evaluate()
    {
        if (_left && _right) {
            _value = _left->Get() - _right->Get();
        }
    }
};

#endif
