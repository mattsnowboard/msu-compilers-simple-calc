#ifndef _PRINTLIST_H
#define _PRINTLIST_H

#include <list>
#include "Expr.h"

/**
 * This class holds a list of things it can print
 * It will own these pointers
 */
class PrintList
{
public:

    PrintList() {}

    void AddItem(Expr* item) { _list.push_back(item); }

    virtual ~PrintList()
    {
        for (std::list<Expr*>::iterator it = _list.begin();
             it != _list.end();
             ++it) {
            delete (*it);
        }
        _list.clear();
    }

    friend std::ostream& operator<<(std::ostream &out, const PrintList& e)
    {
        for (std::list<Expr*>::const_iterator it = e._list.begin();
             it != e._list.end();
             ++it) {
            (*it)->Evaluate();
            out << **it;
        }
        return out;
    }

private:
    std::list<Expr*> _list;
};

#endif
