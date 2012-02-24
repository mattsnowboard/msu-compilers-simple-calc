#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void * CreateNegate(void *expr);
void * CreateSqrt(void *expr);
void * CreateAdd(void *left, void *right);
void * CreateSubtract(void *left, void *right);
void * CreateDivide(void *left, void *right);
void * CreateMultiply(void *left, void *right);
void * CreateExponent(void *left, void *right);
void * CreateLessThan(void *left, void *right);
void * CreateGreaterThan(void *left, void *right);
void * CreateDouble(double d);
void * CreateVariable(const char *name);
void * CreateString(const char *s);
// Used to push back an expression tree for cleanup later
void PushToStack(void *expr);
// Print an expression tree
void PrintExpr(void *expr);
// Assign variable an expression in symbol table
void AssignVariable(const char *name, void *expr);

#endif
