#ifndef _Statements_H
#define _Statements_H

#include <iostream>
#include <stdexcept>

class Statement
{
public:
    Statement() {}

    virtual ~Statement() {}

    virtual void Execute() = 0;

    virtual Statement* Clone() = 0;

};

#endif
