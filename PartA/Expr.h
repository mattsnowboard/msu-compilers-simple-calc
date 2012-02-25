#ifndef _EXPR_H
#define _EXPR_H

#include <iostream>
#include <stdexcept>

class Expr
{
public:
    Expr() : _isEvaluated(false) {}
    virtual ~Expr() {}

    virtual void Evaluate() = 0;

    Expr(Expr& Source):_isEvaluated(Source._isEvaluated){}
    Expr& operator=(Expr& RHS){return *this;}

    /**
     * Print an arbitrary expression to a stream
     */
    friend std::ostream& operator<<(std::ostream &out, const Expr& e)
    {
        if (!e._isEvaluated) {
            throw std::logic_error("Must evaluate before printing!");
        }
        e.Print(out);
        return out;
    }

protected:
    bool _isEvaluated;

private:

    virtual void Print(std::ostream &out) const = 0;
};

#endif
