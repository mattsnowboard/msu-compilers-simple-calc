#ifndef _STDFUNCTION_H
#define _STDFUNCTION_H

#include "StatsFunction.h"
#include <cmath>

class StdFunction : public StatsFunction
{
public:
    StdFunction(NumericalList *l) :
        StatsFunction(l)
    {}

    virtual void Evaluate()
    {
        if (_list) {
            NumericalList::ListT l = _list->Get();
            if (l.size() > 0) {
                double total = 0;
                for (NumericalList::ListT::iterator it = l.begin();
                     it != l.end();
                     it++) {
                    (*it)->Evaluate();
                    total += (*it)->Get();
                }
                double mean = total / l.size();

                double stdev = 0;
                for (NumericalList::ListT::iterator it = l.begin();
                     it != l.end();
                     it++) {
                    (*it)->Evaluate();
                    stdev += std::pow((*it)->Get() - mean, 2);
                }
                stdev = std::sqrt(stdev / (l.size() - 1));
                _value = stdev;
            }
        }
    }

    virtual StdFunction* Clone()
    {
        NumericalList *l = (_list) ? _list->Clone() : NULL;
        StdFunction *s(new StdFunction(l));
        return s;
    }

    virtual void Accept(StatementVisitor &v) const
    {
        v.Visit(*this);
    }
};

#endif
