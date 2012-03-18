#ifndef _VALUE_H
#define _VALUE_H

#include "Numerical.h"

class Value : public Numerical
{
public:
    Value(double v) : Numerical(v) {}

    virtual Value* Clone()
    {
        return new Value(_value);
    }
    
    // NOP
    virtual void Evaluate()
    {
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }
};

#endif
