#ifndef _PRINTSTMT_H
#define _PRINTSTMT_H

#include "Statement.h"
#include "PrintList.h"

class PrintStmt : public Statement
{
public:

    PrintStmt(PrintList *list) :
        _list(list)
    {}

    virtual void Execute()
    {
        // @todo
    }

    virtual PrintStmt* Clone()
    {
        // @todo
    }

    ~PrintStmt()
    {
        // @todo cleanup _list probably
    }

protected:
    PrintList *_list;
};

#endif
