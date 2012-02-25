#ifndef _NUMERICAL_H
#define _NUMERICAL_H

#include "Expr.h"

class Numerical : public Expr
{
public:

    Numerical(double v = 0) : _value(v) {}
    
    Numerical(Numerical& Source):_value(Source.Get()){}
    Numerical& operator=(Numerical& RHS){return *this;}
    
    virtual double Get() const { return _value; }

protected:
    double _value;

private:

    virtual void Print(std::ostream &out) const;
};

#endif
