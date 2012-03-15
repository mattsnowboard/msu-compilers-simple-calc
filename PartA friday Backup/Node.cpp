using namespace std;

#include "Node.h"
#include <iostream>
#include <string.h>



extern CNode * Parent;

extern "C" {
	#include "functions.h"
}

extern "C" void *createAddNode(void *a,  void *b)
{
	AddNodeOp *node = new AddNodeOp((CNode *)a, (CNode *)b);
	return node;
}

extern "C" void *createMinusNode(void *a,  void *b)
{
	MinusNodeOp *node = new MinusNodeOp((CNode *)a, (CNode *)b);
	return node;
}
extern "C" void *createDivideNode(void *a,  void *b)
{
	DivideNodeOp *node = new DivideNodeOp((CNode *)a, (CNode *)b);
	return node;
}
extern "C" void *createMultiplyNode(void *a,  void *b)
{
	MultiplyNodeOp *node = new MultiplyNodeOp((CNode *)a, (CNode *)b);
	return node;
}

extern "C" void *createGrtrThenN(void *a,  void *b)
{
	GrtrThenNode *node = new GrtrThenNode((CNode *)a, (CNode *)b);
	return node;
}

extern "C" void *createLessThenN(void *a,  void *b)
{
	LessThenNode *node = new LessThenNode((CNode *)a, (CNode *)b);
	return node;
}

extern "C" void *createSqrtNode(void *a)
{
	SqrRootNode *node = new SqrRootNode((CNode *)a);
	return node;
}

extern "C" void *createVarNode(const char *a,  int b)
{
	VariableNode *node = new VariableNode( a, b);
	return node;
}
extern "C" void *createAssignmentN(AssignmentNode *a,  CNode* b)
{
	AssignmentNode *node = new AssignmentNode((VariableNode *)a,  (CNode *) b);
	return node;
}

extern "C" void *createEXPNode(CNode *a,  CNode* b)
{
	ExponentNode *node = new ExponentNode((CNode *)a,  (CNode *) b);
	return node;
}
extern "C" void *createParenNode(CNode *a)
{
	ParenthesesNode *node = new ParenthesesNode((CNode *)a);
	return node;
}
extern "C" void *createNodeInt(int n)
{
	CNodeInt *node = new CNodeInt(n);
	return node;
}
extern "C" void *createNodeStr(const char *s)
{
	CNodeStr *node = new CNodeStr(s);
	return node;
}
extern "C" void *createNodeStmts(void *a, void *b)
{
	if(a == NULL)
		return b;

	if(b == NULL)
		return a;

	CNodeStmts *node = new CNodeStmts((CNode *)a, (CNode *)b);
	return node;
}
CNode *g_root = NULL;

extern "C" void setRoot(void *a)
{
	g_root = (CNode *)a;
}

void Execute()
{
	if(g_root != NULL)
		g_root->Evaluate();
}

