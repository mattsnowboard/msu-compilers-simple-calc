#ifndef _STATSFUNCTION_H
#define _STATSFUNCTION_H

#include "Numerical.h"
#include "NumericalList.h"
#include <list>

class StatsFunction : public Numerical
{
public:
    StatsFunction(NumericalList *list) :
        _list(list)
    {}

    virtual ~StatsFunction()
    {
        if (_list) {
            delete _list;
            _list = NULL;
        }
    }

    NumericalList const* GetList() const {
        return _list;
    }

protected:
    NumericalList *_list;
};

#endif
