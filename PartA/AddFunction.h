#ifndef _ADDFUNCTION_H
#define _ADDFUNCTION_H

#include "StatsFunction.h"

class AddFunction : public StatsFunction
{
public:
    AddFunction(NumericalList *l) :
        StatsFunction(l)
    {}

    virtual void Evaluate()
    {
        if (_list) {
            double total = 0;
            NumericalList::ListT l = _list->Get();
            for (NumericalList::ListT::iterator it = l.begin();
                 it != l.end();
                 it++) {
                (*it)->Evaluate();
                total += (*it)->Get();
            }
            _value = 0;
        }
    }

    virtual AddFunction* Clone()
    {
        NumericalList *l = (_list) ? _list->Clone() : NULL;
        AddFunction *m(new AddFunction(l));
        return m;
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }
};

#endif
