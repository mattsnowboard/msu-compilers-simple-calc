#ifndef _ADD_H
#define _ADD_H

#include "Binary.h"

class Add : public Binary
{
public:
    Add(Numerical *left, Numerical *right) :
        Binary(left, right) {}

    virtual void Evaluate()
    {
        if (_left && _right) {
            _left->Evaluate();
            _right->Evaluate();
            _value = _left->Get() + _right->Get();
            _isEvaluated = true;
        }
    }
};

#endif
