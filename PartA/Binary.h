#ifndef _BINARY_H
#define _BINARY_H

#include "Numerical.h"

class Binary : public Numerical
{
public:
    Binary(Numerical *left, Numerical *right) :
        _left(left), _right(right) {}
        
<<<<<<< HEAD
    Binary(Binary& Source):Numerical(Source._value)
=======
    Binary(Binary& Source):Numerical(Source._value),_left(Source._left), _right(Source._right)
>>>>>>> 7d9bde8b54e7a7a2b88af86fe0e1c8b0827ec6b6
    {
        if(Source._left == NULL)
            delete Source._left;
        else
            _left = Source._left;
        if(Source._right == NULL)
            delete Source._right;
        else
            _right = Source._right;
    }
    Binary& operator=(Binary& RHS){return *this;}
    
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
