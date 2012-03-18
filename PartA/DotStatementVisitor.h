#ifndef _DOTSTATEMENTVISITOR_H
#define _DOTSTATEMENTVISITOR_H

#include "StatementVisitor.h"
#include "Statement.h"

#include <iostream>
#include <sstream>

class Unary;
class Binary;

class DotStatementVisitor : public StatementVisitor
{
public:
    DotStatementVisitor(std::ostream &out) :
        _out(out), _parent("\"\"")
    {}

    virtual void Visit(const Add &a);
    virtual void Visit(const AssignStmt &a);
    virtual void Visit(const Divide &d);
    virtual void Visit(const Exponent &e);
    virtual void Visit(const GreaterThan &g);
    virtual void Visit(const IfStmt &i);
    virtual void Visit(const LessThan &l);
    virtual void Visit(const Multiply &m);
    virtual void Visit(const Negate &n);
    virtual void Visit(const PrintStmt &p);
    virtual void Visit(const Sqrt &s);
    virtual void Visit(const String &s);
    virtual void Visit(const Subtract &s);
    virtual void Visit(const UserCommandStmt &u);
    virtual void Visit(const Value &v);
    virtual void Visit(const Variable &v);
    virtual void Visit(const WhileStmt &w);

private:

    std::string GetAddressAsString(const Statement &s)
    {
        std::ostringstream temp;
        temp << '"' << &s << '"';
        return temp.str();
    }

    /**
     * Visit a Binary node
     * @param Binary b The node
     * @param std::string newParent The new _parent string to use
     */
    void VisitBinary(const Binary &b, const std::string &newParent);

    /**
     * Visit a Unary node
     * @param Unary u The node
     * @param std::string newParent The new _parent string to use
     */
    void VisitUnary(const Unary &u, const std::string &newParent);

    /// Where we write the Dot File
    std::ostream &_out;
    /// Current parent string we are processing
    std::string _parent;
    /// Keep a state for labels on children
    std::string _edgeLabel;
};

#endif
