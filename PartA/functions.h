#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

/**
 * Create a negate node
 * @param Expr*
 * @return Expr* (Negate)
 */
void * CreateNegate(void *expr);
/**
 * Create a Square Root node
 * @param Expr*
 * @return Expr* (Sqrt)
 */
void * CreateSqrt(void *expr);
/**
 * Create Add node
 * @param Expr* left
 * @param Expr* right
 * @return Expr* (Add)
 */
void * CreateAdd(void *left, void *right);
/**
 * Create Subtract node
 * @param Expr* left
 * @param Expr* right
 * @return Expr* (Subtract)
 */
void * CreateSubtract(void *left, void *right);
/**
 * Create Divide node
 * @param Expr* left
 * @param Expr* right
 * @return Expr* (Divide)
 */
void * CreateDivide(void *left, void *right);
/**
 * Create Multiply node
 * @param Expr* left
 * @param Expr* right
 * @return Expr* (Multiply)
 */
void * CreateMultiply(void *left, void *right);
/**
 * Create Exponent node
 * @param Expr* left
 * @param Expr* right
 * @return Expr* (Exponent)
 */
void * CreateExponent(void *left, void *right);
/**
 * Create Less Than node
 * @param Expr* left
 * @param Expr* right
 * @return Expr* (LessThan)
 */
void * CreateLessThan(void *left, void *right);
/**
 * Create Greater Than node
 * @param Expr* left
 * @param Expr* right
 * @return Expr* (GreaterThan)
 */
void * CreateGreaterThan(void *left, void *right);
/**
 * Create an AddFunction node for summing a sequence
 * @param NumericalList* list
 * @return Expr* (AddFunction)
 */
void * CreateAddFunction(void *list);
/**
 * Create an MeanFunction node for averaging a sequence
 * @param NumericalList* list
 * @return Expr* (MeanFunction)
 */
void * CreateMeanFunction(void *list);
/**
 * Create an StdFunction node for finding the standard deviation
 * @param NumericalList* list
 * @return Expr* (StdFunction)
 */
void * CreateStdFunction(void *list);
/**
 * Create Value node
 * @param double d
 * @return Expr* (Vale)
 */
void * CreateDouble(double d);
/**
 * Create Variable node
 * @param char* name
 * @return Expr* (Variable)
 */
void * CreateVariable(const char *name);
/**
 * Create String Variable node
 * @param char* name
 * @return Expr* (StrVariable)
 */
void * CreateStrVariable(const char *name);
/**
 * Create String node
 * @param char* string
 * @return Expr* (String)
 */
void * CreateString(const char *s);

/**
 * Create a StatementList with a single statement
 * @param Statement* stmt
 * @return StatementList*
 */
void * CreateStatementList(void *stmt);
/**
 * Add a Statement to a StatementList
 * @param StatementList* stmtlist
 * @param Statement* stmt
 * @return StatementList*
 */
void * AddStatementToList(void *stmtlist, void *stmt);

/**
 * Create a NumericalList with a single Numerical node
 * @param Numerical* node
 * @return NumericalList*
 */
void * CreateNumericalList(void *node);
/**
 * Add a Numerical to a NumericalList
 * @param NumericalList* nodelist
 * @param Numerical* node
 * @return NumericalList*
 */
void * AddNumericalToList(void *nodelist, void *node);

/**
 * Create If Statement
 * @param Expr* cond The condition
 * @param StatementList* stmtlist The statements to execute
 * @return Statement* (IfStmt)
 */
void * CreateIfStmt(void *cond, void *stmtlist);
/**
 * Create While Statement
 * @param Expr* cond The condition
 * @param StatementList* stmtlist The statements to execute
 * @return Statement* (WhileStmt)
 */
void * CreateWhileStmt(void *cond, void *stmtlist);
/**
 * Create a Print Statement
 * @param PrintList* plist
 * @return Statement* (PrintStmt)
 */
void * CreatePrintStmt(void *plist);
/**
 * Create Assignment Statement
 * @param char* name
 * @param Expr*
 * @return Statement* (AssignStmt)
 */
void * CreateAssignStatement(const char *name, void *expr);
/**
 * Create String Assignment Statement
 * @param char* name
 * @param PrintList* list
 * @return Statement* (StrAssignStmt)
 */
void * CreateStrAssignStatement(const char *name, void *list);
/**
 * Add a printable item to a PrintList
 * @param PrintList* plist
 * @param Expr* expr
 * @return PrintList*
 */
void * AddPrintable(void *plist, void *expr);
/**
 * Create a Print List
 * @return PrintList*
 */
void * CreatePrintList();

/**
 * Create a User Command statement
 * @param char* command name
 * @return Statement* (UserCommandStmt)
 */
void * CreateUserCommand(const char *command);

/**
 * Add Statement to Program and Execute
 * @param Statement* stmt
 */
void ExecuteStatement(void *stmt);

#endif
