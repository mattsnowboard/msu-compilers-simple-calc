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

    virtual PrintList* Clone()
    {
        PrintList *p = new PrintList;
        for (std::list<Expr*>::const_iterator it = _list.begin();
             it != _list.end();
             ++it) {
            p->AddItem((*it) ? (*it)->Clone() : NULL);
        }
        return p;
    }
    
    // return type for a const copy of list
    typedef std::list<const Expr*> ListT;

    ListT GetList() const
    {
        ListT cret(_list.begin(), _list.end());
        return cret;
    }

private:

    PrintList(const PrintList&);
    PrintList& operator=(const PrintList&);

    std::list<Expr*> _list;
};

#endif
