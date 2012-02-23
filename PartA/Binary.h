#ifndef _BINARY_H
#define _BINARY_H

#include "Numerical.h"

class Binary : public Numerical
{
public:
    Binary(Numerical *left, Numerical *right) :
        _left(left), _right(right) {}
    virtual ~Binary()
    {
        if (_left != NULL) {
            delete _left;
        }
        if (_right != NULL) {
            delete _right;
        }
    }

protected:
    Numerical *_left;
    Numerical *_right;
};

#endif
