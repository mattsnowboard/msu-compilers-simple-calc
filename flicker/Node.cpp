#include "Node.h"

extern "C" {
#include "functions.h"
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


extern "C" void *createNodeFlicker(void *a, void *b)
{
	CNodeFlicker *node = new CNodeFlicker((CNode *)a, (CNode *)b);
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
