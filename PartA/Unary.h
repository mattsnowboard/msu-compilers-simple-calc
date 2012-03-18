#ifndef _UNARY_H
#define _UNARY_H

#include "Numerical.h"

class Unary : public Numerical
{
public:
    Unary(Numerical *child) : _child(child)
    {
        if (_child) {
            _child->Evaluate();
        }
    }
    
    virtual ~Unary()
    {
        if (_child != NULL) {
            delete _child;
        }
    }

    Numerical const* GetChild() const
    {
        return _child;
    }

protected:
    Numerical *_child;
};

#endif
