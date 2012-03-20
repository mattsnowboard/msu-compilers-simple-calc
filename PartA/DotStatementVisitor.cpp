#include "DotStatementVisitor.h"

#include "Program.h"
#include "Add.h"
#include "AssignStmt.h"
#include "Divide.h"
#include "Exponent.h"
#include "GreaterThan.h"
#include "IfStmt.h"
#include "LessThan.h"
#include "Multiply.h"
#include "Negate.h"
#include "PrintStmt.h"
#include "Sqrt.h"
#include "String.h"
#include "Subtract.h"
#include "UserCommandStmt.h"
#include "Value.h"
#include "Variable.h"
#include "StrVar.h"
#include "WhileStmt.h"

#include "AddFunction.h"
#include "MeanFunction.h"
#include "StdFunction.h"

#include "Binary.h"
#include "Unary.h"
#include "StatsFunction.h"

void DotStatementVisitor::Visit(const Program &p)
{
    _out << "digraph {" << std::endl;

    Program::ProgramListT all = p.GetStatements();
    for (Program::ProgramListT::iterator it = all.begin();
         it != all.end();
         ++it)
    {
        _parent = "\"\"";
        (*it)->Accept(*this);
    }

    _out << "}" << std::endl;
}

void DotStatementVisitor::Visit(const Add &a)
{
    std::string current(GetAddressAsString(a));
    _out << "\t" << current << "[label=\"+\"]" << std::endl;
    VisitBinary(a, current);
}

void DotStatementVisitor::Visit(const AssignStmt & a)
{
    std::string current(GetAddressAsString(a));
    _out << "\t" << current << "[label=\"Assign\"]"
         << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = current;
    _edgeLabel = "[label=\"variable\"]";
    _out << "\t" << _parent << "->" << a.GetName() << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = current;
    a.GetValue()->Accept(*this);
    _edgeLabel = "";
}

void DotStatementVisitor::Visit(const StrAssignStmt & a)
{
  /*  std::string current(GetAddressAsString(a));
    _out << "\t" << current << "[label=\"Assign\"]"
         << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = current;
    _edgeLabel = "[label=\"variable\"]";
    _out << "\t" << _parent << "->" << a.GetName() << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = current;
    a.GetStrName()->Accept(*this);
    _edgeLabel = "";

    const PrintList *slist = p.GetList();
    PrintList::ListT list = slist->GetList();
    for (PrintList::ListT::iterator it = list.begin();
         it != list.end();
         ++it) {
        _parent = current;
        (*it)->Accept(*this);
    }
*/
}

void DotStatementVisitor::Visit(const Divide & d)
{
    std::string current(GetAddressAsString(d));
    _out << "\t" << current << "[label=\"/\"]" << std::endl;
    VisitBinary(d, current);
}

void DotStatementVisitor::Visit(const Exponent & e)
{
    std::string current(GetAddressAsString(e));
    _out << "\t" << current << "[label=\"^\"]" << std::endl;
    VisitBinary(e, current);
}

void DotStatementVisitor::Visit(const GreaterThan & g)
{
    std::string current(GetAddressAsString(g));
    _out << "\t" << current << "[label=\">\"]" << std::endl;
    VisitBinary(g, current);
}

void DotStatementVisitor::Visit(const IfStmt & i)
{
    std::string current(GetAddressAsString(i));
    _out << "\t" << current << "[label=\"if\"]" << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = current;
    _edgeLabel = "[label=\"condition\"]";
    i.GetCondition()->Accept(*this);
    _edgeLabel = "";

    _parent = current;
    // create a dummy node to hold a block of statements
    current = current.substr(0, current.size() - 1) + "_block\"";
    _out << "\t" << current << "[label=\"{}\"]" << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    const StatementList *slist = i.GetStatements();
    StatementList::ListT list = slist->GetStatements();
    for (StatementList::ListT::iterator it = list.begin();
         it != list.end();
         ++it) {
        _parent = current;
        (*it)->Accept(*this);
    }
}

void DotStatementVisitor::Visit(const LessThan & l)
{
    std::string current(GetAddressAsString(l));
    _out << "\t" << current << "[label=\"<\"]" << std::endl;
    VisitBinary(l, current);
}

void DotStatementVisitor::Visit(const Multiply & m)
{
    std::string current(GetAddressAsString(m));
    _out << "\t" << current << "[label=\"*\"]" << std::endl;
    VisitBinary(m, current);
}

void DotStatementVisitor::Visit(const Negate & n)
{
    std::string current(GetAddressAsString(n));
    _out << "\t" << current << "[label=\"-\"]" << std::endl;
    VisitUnary(n, current);
}

void DotStatementVisitor::Visit(const PrintStmt & p)
{
    std::string current(GetAddressAsString(p));
    _out << "\t" << current << "[label=\"print\"]"
         << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    const PrintList *slist = p.GetList();
    PrintList::ListT list = slist->GetList();
    for (PrintList::ListT::iterator it = list.begin();
         it != list.end();
         ++it) {
        _parent = current;
        (*it)->Accept(*this);
    }
}

void DotStatementVisitor::Visit(const Sqrt & s)
{
    std::string current(GetAddressAsString(s));
    _out << "\t" << current << "[label=\"sqrt\"]" << std::endl;
    VisitUnary(s, current);
}

void DotStatementVisitor::Visit(const String &s)
{
    std::string current(GetAddressAsString(s));
    _out << "\t" << current << "[label=\"<string, " << s.GetString() << ">\"]"
         << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";
}

void DotStatementVisitor::Visit(const Subtract &s)
{
    std::string current(GetAddressAsString(s));
    _out << "\t" << current << "[label=\"-\"]" << std::endl;
    VisitBinary(s, current);
}

void DotStatementVisitor::Visit(const UserCommandStmt & u)
{
    std::string current(GetAddressAsString(u));
    _out << "\t" << current << "[label=\"<cmd, " << u.GetCommand() << ">\"]"
         << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";
}

void DotStatementVisitor::Visit(const Value & v)
{
    std::string current(GetAddressAsString(v));
    _out << "\t" << current << "[label=\"<value, " << v.Get() << ">\"]"
         << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";
}

void DotStatementVisitor::Visit(const Variable & v)
{
    std::string current(GetAddressAsString(v));
    _out << "\t" << current << "[label=\"<variable, " << v.GetName() << ">\"]"
         << std::endl;
    VisitUnary(v, current);
}

void DotStatementVisitor::Visit(const StrVar & v)
{
    std::string current(GetAddressAsString(v));
    _out << "\t" << current << "[label=\"<variable, " << v.GetName() << ">\"]"
         << std::endl;
//    VisitUnary(v, current);
}

void DotStatementVisitor::Visit(const WhileStmt & w)
{
    std::string current(GetAddressAsString(w));
    _out << "\t" << current << "[label=\"while\"]" << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = current;
    _edgeLabel = "[label=\"condition\"]";
    w.GetCondition()->Accept(*this);
    _edgeLabel = "";

    _parent = current;
    // create a dummy node to hold a block of statements
    current = current.substr(0, current.size() - 1) + "_block\"";
    _out << "\t" << current << "[label=\"{}\"]" << std::endl;
    _out << "\t" << _parent << "->" << current << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    const StatementList *slist = w.GetStatements();
    StatementList::ListT list = slist->GetStatements();
    for (StatementList::ListT::iterator it = list.begin();
         it != list.end();
         ++it) {
        _parent = current;
        (*it)->Accept(*this);
    }
}

void DotStatementVisitor::Visit(const AddFunction &f)
{
    std::string current(GetAddressAsString(f));
    _out << "\t" << current << "[label=\"add()\"]" << std::endl;
    VisitStatsFunc(f, current);
}

void DotStatementVisitor::Visit(const MeanFunction &f)
{
    std::string current(GetAddressAsString(f));
    _out << "\t" << current << "[label=\"mean()\"]" << std::endl;
    VisitStatsFunc(f, current);
}

void DotStatementVisitor::Visit(const StdFunction &f)
{
    std::string current(GetAddressAsString(f));
    _out << "\t" << current << "[label=\"std()\"]" << std::endl;
    VisitStatsFunc(f, current);
}

void DotStatementVisitor::VisitBinary(const Binary &b,
                                      const std::string &newParent)
{
    _out << "\t" << _parent << "->" << newParent << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = newParent;
    b.GetLeft()->Accept(*this);

    _parent = newParent;
    b.GetRight()->Accept(*this);
}

void DotStatementVisitor::VisitUnary(const Unary &u,
                                     const std::string &newParent)
{
    _out << "\t" << _parent << "->" << newParent << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";

    _parent = newParent;
    u.GetChild()->Accept(*this);
}

void DotStatementVisitor::VisitStatsFunc(const StatsFunction &f,
                                         const std::string &newParent)
{
    _out << "\t" << _parent << "->" << newParent << " "
         << _edgeLabel << std::endl;
    _edgeLabel = "";


    const NumericalList *nlist = f.GetList();
    NumericalList::ListCT list = nlist->Get();
    for (NumericalList::ListCT::iterator it = list.begin();
         it != list.end();
         ++it) {
        _parent = newParent;
        (*it)->Accept(*this);
    }
}
