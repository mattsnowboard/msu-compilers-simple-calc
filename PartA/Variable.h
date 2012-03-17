#ifndef _VARIABLE_H
#define _VARIABLE_H

#include "Unary.h"
#include "SymbolTable.h"
#include <string>

/**
 * Note Variable is not a Unary
 * Variable does not own its child like Unary does, SymbolTable owns it
 * @Matt 2/26/12
 * Now Variable does own the child
 */
class Variable : public Unary
{
public:
    Variable(const std::string &s) : Unary(NULL), _name(s) {}

    std::string GetName() const { return _name; }
    

    virtual Variable* Clone()
    {
        Variable *v = new Variable(_name);
        v->_child = (_child) ? _child->Clone() : NULL;
        return v;
    }

    virtual void Evaluate()
    {
        if (!_child) {
            SymbolTable &s = SymbolTable::GetInstance();
            if (s.DoesExist(_name)) {
                Numerical *temp = s.GetVal(_name);
                // Now Variable owns this
                _child = temp->Clone();
            }
            else {
                std::cout << "Variable: " << _name << " not defined." << std::endl;
                _value = 0;
                _isEvaluated = true;
            }
        }
        if (_child) {
            _child->Evaluate();
            _value = _child->Get();
        }
    }

protected:
    std::string _name;
    // this may prove useful...or we can delete it safely
    bool _isEvaluated;
};

#endif
