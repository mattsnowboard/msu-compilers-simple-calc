#ifndef _LESSTHAN_H
#define _LESSTHAN_H

#include "Binary.h"

class LessThan : public Binary
{
public:
    LessThan(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual void Evaluate()
    {
        if (_left && _right) {
            _value = (_left->Get() < _right->Get()) ? 1 : 0;
        }
    }
};

#endif
