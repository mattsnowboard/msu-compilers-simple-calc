#ifndef _UNARY_H
#define _UNARY_H

#include "Numerical.h"

class Unary : public Numerical
{
public:
    Unary(Numerical *child) : _child(child) {}
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
