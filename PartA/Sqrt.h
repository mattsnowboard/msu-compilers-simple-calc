#ifndef _SQRT_H
#define _SQRT_H

#include "Unary.h"
#include <cmath>

class Sqrt : public Unary
{
public:
    Sqrt(Numerical *child) : Unary(child) {}

    virtual void Evaluate()
    {
        if (_child) {
            _child->Evaluate();
            _value = std::sqrt(_child->Get());
        }
    }
};

#endif
