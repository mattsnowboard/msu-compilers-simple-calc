#ifndef _CONDITIONAL_H
#define _CONDITIONAL_H

#include "Statement.h"



class Conditional : public Statements
{
public:
    Conditional(Statements *left, Statements *right) :
        Statements(left, right) {}
    virtual ~Conditional() {}

    virtual void Evaluate();


protected:
    bool _isEvaluated;


};

#endif
