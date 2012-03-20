#ifndef _STRVAR_H
#define _STRVAR_H

#include "StrSymbolTable.h"
#include <string>

// This can't be Unary because its child is not Numerical
class StrVar : public Expr
{
public:
    StrVar(const std::string &s) : _name(s) {}

    std::string GetName() const { return _name; }

    virtual StrVar* Clone()
    {
        StrVar *v = new StrVar(_name);
        v->_child = (_child) ? _child->Clone() : NULL;
        return v;
    }

    virtual void Evaluate()
    {
        // here we want to always re-evaluate
        if (_child) {
            delete _child;
        }
        
        StrSymbolTable &s = StrSymbolTable::GetInstance();
        if (s.DoesExist(_name)) {
            Expr *temp = s.GetStr(_name);
            // Now Variable owns this
            _child = temp->Clone();
        }
        else {
            std::cout << "Variable: " << _name << " not defined." << std::endl;
        }

        if (_child) {
            _child->Evaluate();
        }
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }

protected:
    std::string _name;

    Expr *_child;

private:

    virtual void Print(std::ostream &out) const
    {
        out << _child;
    }
};

#endif
