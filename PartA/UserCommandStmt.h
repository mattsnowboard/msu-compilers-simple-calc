#ifndef _USRCOMMANDSTMT_H
#define _USERCOMMANDSTMT_H

#include "Statement.h"
#include "SymbolTable.h"
#include "ExitException.h"

class UserCommandStmt : public Statement
{
public:

    UserCommandStmt(const char* command) :
        _command(command)
    {}

    virtual void Execute()
    {
        if(!_command.compare("exit"))
        {
            throw ExitException();
        }
        if(!_command.compare( "help"))
        {
             std::cout << "*************SimpleCalc Help*************" << std::endl << std::endl;
             std::cout << "*************Available Commands**********" << std::endl;
             std::cout << "exit       :     Quits the current SimpleCalc program or command prompt" << std::endl;
             std::cout << "clear      :     Clears the current Symbol Table, resetting variable declarations.\n\
                     Note, all variables must be redeclared before use, otherwise they default to value 0." << std::endl;
             std::cout << "help       :     Print this help message." << std::endl << std::endl;
             std::cout << "*************Programming Grammar*********" << std::endl;
             std::cout << "Comments   :     Lines beginning with # are ignored by the interpreter and are comments.\n\
                     Any text betwen  and  are ignored by the interpreter and are also comments." << std::endl;
             
             std::cout << "Variables  :     A variable is declared by using the \":=\" operator.\n\
                     EXAMPLE:\n\
                     a:=2" << std::endl;    
        }
        if(!_command.compare("clear"))
        {
            SymbolTable &theTable = SymbolTable::GetInstance();
            theTable.Clear();
        }
        
    }

    virtual UserCommandStmt* Clone()
    {
        UserCommandStmt* cmd = new UserCommandStmt(_command.c_str());
        return cmd;
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }

protected:
    std::string _command;
};

#endif
