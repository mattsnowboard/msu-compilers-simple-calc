#ifndef _GREATERTHAN_H
#define _GREATERTHAN_H

#include "Binary.h"

class GreaterThan : public Binary
{
public:
    GreaterThan(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual void Evaluate()
    {
        if (_left && _right) {
            _value = (_left->Get() > _right->Get()) ? 1 : 0;
        }
    }
};

#endif
