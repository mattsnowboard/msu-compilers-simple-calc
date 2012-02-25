#ifndef _UNARY_H
#define _UNARY_H

#include "Numerical.h"

class Unary : public Numerical
{
public:
    Unary(Numerical *child) : _child(child) {}
    
    Unary(Unary& Source):Numerical(Source._value)
    {
        if(Source._child == NULL)
            delete Source._child;
        else
            _child = Source._child;
    }
    Unary& operator=(Unary& RHS){return *this;}
    
    virtual ~Unary()
    {
        if (_child != NULL) {
            delete _child;
        }
    }

protected:
    Numerical *_child;
};

#endif
