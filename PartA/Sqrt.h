#ifndef _SQRT_H
#define _SQRT_H

#include "Unary.h"
#include <cmath>

class Sqrt : public Unary
{
public:
    Sqrt(Numerical *child) : Unary(child) {}

    virtual Sqrt* Clone()
    {
        Numerical *c = (_child) ? _child->Clone() : NULL;
        Sqrt *u = new Sqrt(c);
        return u;
    }

    virtual void Evaluate()
    {
        if (_child) {
            _child->Evaluate();
            _value = std::sqrt(_child->Get());
            _isEvaluated = true;
        }
    }
};

#endif
