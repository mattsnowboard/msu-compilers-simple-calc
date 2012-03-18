#ifndef _ASSIGNSTMT_H
#define _ASSIGNSTMT_H

#include "Statement.h"

class AssignStmt : public Statement
{
public:

    AssignStmt(const std::string &name, Numerical *value) :
        _name(name), _value(value)
    {}

    virtual void Execute()
    {
        // @todo
    }

    virtual AssignStmt* Clone()
    {
        // @todo 
        return this;
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }

    ~AssignStmt()
    {
        // @todo Maybe don't need to clean this, I think SymbolTable will
        // still own the pointer to _value...
    }

protected:
    std::string _name;
    Numerical* _value;
};

#endif
