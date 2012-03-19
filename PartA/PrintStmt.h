#ifndef _PRINTSTMT_H
#define _PRINTSTMT_H

#include "Statement.h"
#include "PrintList.h"

#include <iostream>

class PrintStmt : public Statement
{
public:

    PrintStmt(PrintList *list) :
        _list(list)
    {}

    virtual void Execute()
    {
        std::cout << *_list << std::endl;
    }

    virtual PrintStmt* Clone()
    {
        PrintList *l = (_list) ? _list->Clone() : NULL;
        PrintStmt *p = new PrintStmt(l);
        return p;
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }

    PrintList const* GetList() const
    {
        return _list;
    }

    ~PrintStmt()
    {
        if (_list) {
            delete _list;
        }
    }

protected:
    PrintList *_list;
};

#endif
