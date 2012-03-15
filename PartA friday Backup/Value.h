#ifndef _VALUE_H
#define _VALUE_H

#include "Numerical.h"

class Value : public Numerical
{
public:
    Value(double v) : Numerical(v) {}
    
    // NOP
    virtual void Evaluate() {}
};

#endif
