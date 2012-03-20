#ifndef _STATEMENTVISITOR_H
#define _STATEMENTVISITOR_H

class Program;

class Add;
class AssignStmt;
class Divide;
class Exponent;
class GreaterThan;
class IfStmt;
class LessThan;
class Multiply;
class Negate;
class PrintStmt;
class Sqrt;
class String;
class Subtract;
class UserCommandStmt;
class Value;
class Variable;
class WhileStmt;
class AddFunction;
class MeanFunction;
class StdFunction;

class StatementVisitor
{
public:
    virtual void Visit(const Program &p) = 0;
    virtual void Visit(const Add &a) = 0;
    virtual void Visit(const AssignStmt &a) = 0;
    virtual void Visit(const Divide &d) = 0;
    virtual void Visit(const Exponent &e) = 0;
    virtual void Visit(const GreaterThan &g) = 0;
    virtual void Visit(const IfStmt &i) = 0;
    virtual void Visit(const LessThan &l) = 0;
    virtual void Visit(const Multiply &m) = 0;
    virtual void Visit(const Negate &n) = 0;
    virtual void Visit(const PrintStmt &p) = 0;
    virtual void Visit(const Sqrt &s) = 0;
    virtual void Visit(const String &s) = 0;
    virtual void Visit(const Subtract &s) = 0;
    virtual void Visit(const UserCommandStmt &u) = 0;
    virtual void Visit(const Value &v) = 0;
    virtual void Visit(const Variable &v) = 0;
    virtual void Visit(const WhileStmt &w) = 0;
    virtual void Visit(const AddFunction &f) = 0;
    virtual void Visit(const MeanFunction &f) = 0;
    virtual void Visit(const StdFunction &f) = 0;
};

#endif
