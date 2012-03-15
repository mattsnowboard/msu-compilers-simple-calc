#ifndef _Statements_H
#define _Statements_H

#include <iostream>
#include <stdexcept>

class Statements :public Binary
{
public:
    Statements(Binary *left, Binary *right) :
        Binary(left, right) {}

    virtual ~Statements() {}

    virtual void Evaluate() = 0;


protected:
    bool _isEvaluated;

    double result;

};

#endif
