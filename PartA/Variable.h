#ifndef _VARIABLE_H
#define _VARIABLE_H

#include "Unary.h"
#include "SymbolTable.h"
#include <string>




class Variable : public Unary
{
public:
    Variable(std::string s, Numerical *child) : Unary(child), _name(s) {}

    std::string GetName() const { return _name; }

    virtual void Evaluate()
    {
        if (_child) {
            _child->Evaluate();
            _value = _child->Get();

	if(!symTable->DoesExist(_name))
	{
	  symTable->AddVar( _name,_child );
	}

	else{}

        }
    }

protected:
    std::string _name;
    
};

#endif
