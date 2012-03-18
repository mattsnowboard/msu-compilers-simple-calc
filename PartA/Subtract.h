#ifndef _SUBTRACT_H
#define _SUBTRACT_H

#include "Binary.h"

class Subtract : public Binary
{
public:
    Subtract(Numerical *left, Numerical *right) :
        Binary(left, right) {}
        
    virtual Subtract* Clone()
    {
        Numerical *l = (_left) ? _left->Clone() : NULL;
        Numerical *r = (_right) ? _right->Clone() : NULL;
        Subtract *b = new Subtract(l, r);
        return b;
    }

    virtual void Evaluate()
    {
        if (_left && _right) {
            _left->Evaluate();
            _right->Evaluate();
            _value = _left->Get() - _right->Get();
        }
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }
};

#endif
