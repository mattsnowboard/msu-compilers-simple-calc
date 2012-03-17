#ifndef _USRCOMMANDSTMT_H
#define _USERCOMMANDSTMT_H

#include "Statement.h"

class UserCommandStmt : public Statement
{
public:

    UserCommandStmt(const std::string &command) :
        _command(command)
    {}

    virtual void Execute()
    {
        // @todo
    }

    virtual AssignStmt* Clone()
    {
        // @todo
    }

protected:
    std::string _command;
};

#endif
