#ifndef _NUMERICALLIST_H
#define _NUMERICALLIST_H

#include <list>
#include "Numerical.h"

/**
 * This class holds a list of Numericals
 * It is a helpful wrapper around std::list for Stats functions
 */
class NumericalList
{
public:

    NumericalList() {}

    void AddItem(Numerical* item) { _list.push_back(item); }

    virtual ~NumericalList()
    {
        for (std::list<Numerical*>::iterator it = _list.begin();
             it != _list.end();
             ++it) {
            delete (*it);
        }
        _list.clear();
    }

    NumericalList* Clone()
    {
        NumericalList *s = new NumericalList;
        // simple copy
        for (std::list<Numerical*>::iterator it = _list.begin();
             it != _list.end();
             ++it ) {
            if (*it) {
                s->_list.push_back((*it)->Clone());
            }
        }

        return s;
    }

    typedef std::list<const Numerical*> ListT;

    ListT Get() const
    {
        ListT cret(_list.begin(), _list.end());
        return cret;
    }

private:
    std::list<Numerical*> _list;
};

#endif
