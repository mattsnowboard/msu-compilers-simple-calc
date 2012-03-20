#ifndef _STRVAR_H
#define _STRVAR_H

#include "Unary.h"
#include "SymbolTable.h"
#include <string>

/**
 * Note StrVar is not a Unary
 * StrVar does not own its child like Unary does, SymbolTable owns it
 * @Matt 2/26/12
 * Now StrVar does own the child
 */
class StrVar : public Unary
{
public:
    StrVar(const std::string &s) : Unary(NULL), _name(s) {}

    std::string GetName() const { return _name; }
    

    virtual StrVar* Clone()
    {
        StrVar *v = new StrVar(_name);
        v->_child = (_child) ? _child->Clone() : NULL;
        return v;
    }

    virtual void Evaluate()
    {
        if (!_child) {
            SymbolTable &s = SymbolTable::GetInstance();
            if (s.DoesExist(_name)) {
                Numerical *temp = s.GetVal(_name);
                _child = temp->Clone();
            }
            else {
                _value = 0;
                _isEvaluated = true;
            }
        }
        if (_child) {
            _child->Evaluate();
            _value = _child->Get();
        }
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }

protected:
    std::string _name;
    // this may prove useful...or we can delete it safely
    bool _isEvaluated;
};

#endif
