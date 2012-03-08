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
// Used to push back a printlist for cleanup later
void PushToPrintStack(void *pl);
// Print an expression tree
void PrintExpr(void *expr);
// Assign variable an expression in symbol table
void AssignVariable(const char *name, void *expr);
// Add to a print list
void * AddPrintable(void *plist, void *expr);
void * CreatePrintList();
void PrintPrintList(void *plist);
void PrintUserSupport(const char *command);

#endif
