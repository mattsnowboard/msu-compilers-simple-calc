#ifndef _EXPR_H
#define _EXPR_H

#include <iostream>

class Expr
{
public:
    Expr() {}
    virtual ~Expr() {}

    virtual void Evaluate() = 0;

    /**
     * Print an arbitrary expression to a stream
     */
    friend std::ostream& operator<<(std::ostream &out, const Expr& e)
    {
        e.Print(out);
        return out;
    }

private:

    virtual void Print(std::ostream &out) const = 0;
};

#endif
