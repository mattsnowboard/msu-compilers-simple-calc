#ifndef _MEANFUNCTION_H
#define _MEANFUNCTION_H

#include "StatsFunction.h"

class MeanFunction : public StatsFunction
{
public:
    MeanFunction(NumericalList *l) :
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
            if (l.size() > 0) {
                _value = total / l.size();
            }
        }
    }

    virtual MeanFunction* Clone()
    {
        NumericalList *l = (_list) ? _list->Clone() : NULL;
        MeanFunction *m(new MeanFunction(l));
        return m;
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }
};

#endif
