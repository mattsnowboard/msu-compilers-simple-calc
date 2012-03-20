#ifndef _STRASSIGNSTMT_H
#define _STRASSIGNSTMT_H

#include "StrSymbolTable.h"
#include "Statement.h"
#include "Value.h"

class StrAssignStmt : public Statement
{
public:

    StrAssignStmt(const std::string &name, Expr *StrName) :
        _name(name), _StrName(StrName)
    {}

    virtual void Execute()
    {
       if (_StrName) {
            StrSymbolTable &s = StrSymbolTable::GetInstance();
            // create a new Value of the current Numerical StrName
            // that new Value will be owned by SymbolTable
            // But this owns its _StrName pointer now
            _StrName->Evaluate();
            s.AddVar(_name, _StrName);
        }
	}

    virtual StrAssignStmt* Clone()
    {
        Expr *v = (_StrName) ? _StrName->Clone() : NULL;
        StrAssignStmt *a = new StrAssignStmt(_name, v);
        return a;
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }

    const std::string& GetName() const
    {
        return _name;
    }

    Expr const* GetStrName() const
    {
        return _StrName;
    }

    ~StrAssignStmt()
    {
        // actually, we do need to own _StrName
        if (_StrName) {
            delete _StrName;
        }
    }

protected:
    std::string _name;
    Expr* _StrName;
};

#endif
