#ifndef _NUMERICAL_H
#define _NUMERICAL_H

#include "Expr.h"
#include "SymbolTable.h"

class Numerical : public Expr
{
public:

    SymbolTable *symTable;
    Numerical(double v = 0) : _value(v) {}

    virtual double Get() const { return _value; }

protected:
    double _value;

private:

    virtual void Print(std::ostream &out) const;
};

#endif
