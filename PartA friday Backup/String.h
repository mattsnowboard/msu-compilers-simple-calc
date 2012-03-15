#ifndef _STRING_H
#define _STRING_H

#include "Expr.h"
#include <string>

class String : public Expr
{
public:

    String(std::string s) : _value(s) {}

    // NOP
    virtual void Evaluate() {}

private:
    std::string _value;

    virtual void Print(std::ostream &out) const 
    {
        out << _value;
    }
};

#endif
