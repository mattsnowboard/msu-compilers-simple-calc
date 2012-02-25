#ifndef _STRING_H
#define _STRING_H

#include "Expr.h"
#include <string>

class String : public Expr
{
public:

    String(std::string s) : _value(s.substr(1,s.length()-2)) {}
    
    String(String& Source):Expr(),_value(Source._value){}
    String& operator=(String & RHS){return *this;}

    // NOP
    virtual void Evaluate()
    {
        _isEvaluated = true;
    }

private:
    std::string _value;

    virtual void Print(std::ostream &out) const 
    {
        out << _value;
    }
};

#endif
