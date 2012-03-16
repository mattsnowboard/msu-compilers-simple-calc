#ifndef _NUMERICAL_H
#define _NUMERICAL_H

#include "Expr.h"
#include <iostream>

class Numerical : public Expr
{
public:

    Numerical(double v = 0) : _value(v) {}

    virtual Numerical* Clone() = 0;

    virtual double Get() const { return _value; }

protected:
    double _value;

private:

    virtual void Print(std::ostream &out) const;
};

#endif
