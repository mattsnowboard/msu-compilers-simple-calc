#ifndef _STRASSIGNSTMT_H
#define _STRASSIGNSTMT_H

#include "StrSymbolTable.h"
#include "Statement.h"
#include "PrintList.h"
#include <iostream>
#include <sstream>
#include <string>

class StrAssignStmt : public Statement
{
public:

    StrAssignStmt(const std::string &name, PrintList *Str) :
        _name(name), _Str(Str)
    {}

    virtual void Execute()
    {
       if (_Str) {
            StrSymbolTable &s = StrSymbolTable::GetInstance();
 	    
            // create a new Value of the current Numerical StrName
            // that new Value will be owned by SymbolTable
            // But this owns its _StrName pointer now
            std::ostringstream ss;
            

            // need dummy quotes which we strip out in String
            ss << "\"" <<  *_Str << "\"";
            String *strVal = new String(ss.str());
            s.AddVar(_name, strVal);
        }
	}

    virtual StrAssignStmt* Clone()
    {
        PrintList *v = (_Str) ? _Str->Clone() : NULL;
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

    PrintList const* GetStr() const
    {
        return _Str;
    }

    ~StrAssignStmt()
    {
        // actually, we do need to own _Str
        if (_Str) {
            delete _Str;
        }
    }

protected:
    std::string _name;
    PrintList* _Str;
};

#endif
