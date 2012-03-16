#ifndef _MY_STRING_H
#define _MY_STRING_H

#include "Expr.h"
#include <string>

class String : public Expr
{
public:

    String(std::string s) : _value(s.substr(1,s.length()-2)) {}

    virtual String* Clone()
    {
        std::string temp(_value);
        temp = "\"" + temp + "\"";
        return new String(temp);
    }
    
    // NOP
    virtual void Evaluate()
    {
    }

private:
    std::string _value;

    virtual void Print(std::ostream &out) const 
    {
        out << _value;
    }
};

#endif
