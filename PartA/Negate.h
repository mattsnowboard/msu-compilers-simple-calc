#ifndef _NEGATE_H
#define _NEGATE_H

#include "Unary.h"

class Negate : public Unary
{
public:
    Negate(Numerical *child) : Unary(child) {}

    virtual Negate* Clone()
    {
        Numerical *c = (_child) ? _child->Clone() : NULL;
        Negate *u = new Negate(c);
        return u;
    }

    virtual void Evaluate()
    {
        if (_child) {
            _child->Evaluate();
            _value = -_child->Get();
        }
    }
};

#endif
