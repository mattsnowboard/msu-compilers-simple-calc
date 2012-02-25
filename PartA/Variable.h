#ifndef _VARIABLE_H
#define _VARIABLE_H

#include "Unary.h"
#include "SymbolTable.h"
#include <string>

/**
 * Note Variable is not a Unary
 * Variable does not own its child like Unary does, SymbolTable owns it
 */
class Variable : public Numerical
{
public:
    Variable(std::string s) : _name(s), _child(NULL) {}

    std::string GetName() const { return _name; }

    virtual void Evaluate()
    {
        if (!_child) {
            SymbolTable &s = SymbolTable::GetInstance();
            if (s.DoesExist(_name)) {
                _child = s.GetVal(_name);
            }
            else{
                std::cout << "Variable: " << _name << " not defined." << std::endl;
                _value = 0;
                _isEvaluated = true;
            }
        }
        if (_child) {
            _child->Evaluate();
            _value = _child->Get();
	}

	else{}

            _isEvaluated = true;
        

    }

protected:
    std::string _name;
    Numerical *_child;
};

#endif
