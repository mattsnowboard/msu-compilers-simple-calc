#ifndef _ASSIGNSTMT_H
#define _ASSIGNSTMT_H

#include "SymbolTable.h"
#include "Statement.h"

class AssignStmt : public Statement
{
public:

    AssignStmt(const std::string &name, Numerical *value) :
        _name(name), _value(value)
    {}

    virtual void Execute()
    {

       if (!_value) {
            SymbolTable &s = SymbolTable::GetInstance();
            if (s.DoesExist(_name)) {
                Numerical *temp = s.GetVal(_name);
                _value = temp->Clone();
            }
            else {
                _value = 0;
            }
        if (_value)
        {
            _value->Evaluate(); 
            
        }
	}

    }

    virtual AssignStmt* Clone()
    {
        AssignStmt *a = new AssignStmt(_name, _value);
        a->_value = (_value) ? _value->Clone() : NULL;
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
