#ifndef _VALUE_H
#define _VALUE_H

#include "Numerical.h"

class Value : public Numerical
{
public:
    Value(double v) : Numerical(v) {}
    
    Value(Value& Source):Numerical(Source._value){}
    Value& operator=(Value& RHS){return *this;}
    
    // NOP
    virtual void Evaluate()
    {
        _isEvaluated = true;
    }
};

#endif
