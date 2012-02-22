#ifndef _NODE_H
#define _NODE_H


#include <iostream>
#include <string.h>


using namespace std;

class Val
{
public:	enum Type {NONE, INT, STR};
	Val() {type = NONE;}
	Val(int i) {type = INT;  ival = i;}
	Val(std::string &s) {type = STR;  sval = new std::string(s);}
	~Val() {if(type == STR) {delete sval;}}
	
	Val(const Val &v)
	{
		if(v.GetType() == INT)
		{
			type = INT;
			ival = v.IVal();
		}
		else if(v.GetType() == STR)
		{
			type = STR;
			sval = new std::string(v.SVal());
		}
	}

	Val &operator=(const Val &v)
	{
		//if(type == STR) {delete sval;}
		string s = v.SVal();
		if(s.compare(">")){}


		if(v.GetType() == INT)
		{
			type = INT;
			ival = v.IVal();
		}

		else if(v.GetType() == STR)
		{
			type = STR;
			sval = new std::string(v.SVal());
		}
	}


	Type GetType() const {return type;}
	int IVal() const {return ival;}
	const std::string &SVal() const {return *sval;}

private:
	Type  type;
	union
	{
		std::string  *sval;
		int           ival;
	};	
};

class CNode
{
public:
//	string& GetSymbol(){ return *sval;}
	CNode(void) {}
	virtual ~CNode(void) {}
	virtual void Evaluate() {}
	enum Type {NONE, INT, STR};
	//Val() {type = NONE;}
	//int Val(int i) {type = INT;  ival = i;}
	//string &STRING() {return *sval;}



	CNode(CNode &v)
	{
		if(v.GetType() == INT)
		{
			type = INT;
			ival = v.IVal();

		}
		else if(v.GetType() == STR)
		{
			type = STR;
			sval = new std::string(v.SVal());
		}
	}
	Type GetType() const {return type;}
	int IVal() const {return ival;}
	const std::string &SVal() const {return *sval;}
private:
	Type  type;
	union

	{
		std::string  *sval;
		int           ival;
	};

};


class AddNodeOp : public CNode
{
public:
	AddNodeOp(CNode *left, CNode *right)  { nleft = left; nright = right;}

	~AddNodeOp(){delete nleft; delete nright;}
	virtual int Calculate()
	{
		
		if((nleft->GetType() & nright->GetType()) == INT)
		{
			int x = nleft->IVal();
			int y = nright->IVal();
			int z = x+y;
			return z;
		}
		else{}



	}



private:
	CNode* nleft;
	CNode* nright;

	int count;
};


class MinusNodeOp : public CNode
{
public:
	MinusNodeOp(CNode *left, CNode *right)  { nleft = left; nright = right;}

	~MinusNodeOp(){delete nleft; delete nright;}

	virtual int Calculate()
	{
		
		if((nleft->GetType() & nright->GetType()) == INT)
		{
			int x = nleft->IVal();
			int y = nright->IVal();
			int z = x-y;
			return z;
		}
		else{}



	}


private:
	CNode* nleft;
	CNode* nright;

	int count;
};

class MultiplyNodeOp : public CNode
{
public:
	MultiplyNodeOp(CNode *left, CNode *right)  { nleft = left; nright = right;}

	~MultiplyNodeOp(){delete nleft; delete nright;}

	virtual int Calculate()
	{
		
		if((nleft->GetType() & nright->GetType()) == INT)
		{
			int x = nleft->IVal();
			int y = nright->IVal();
			int z = x*y;
			return z;
		}
		else{}



	}


private:
	CNode* nleft;
	CNode* nright;

	int count;
};


class DivideNodeOp : public CNode
{
public:
	DivideNodeOp(CNode *left, CNode *right)  { nleft = left; nright = right;}

	~DivideNodeOp(){delete nleft; delete nright;}

	virtual int Calculate()
	{
		
		if((nleft->GetType() & nright->GetType()) == INT)
		{if {nright->IVal() == 0) {}
		else{	int x = nleft->IVal();
			int y = nright->IVal();
			int z = x+y;
			return z;}
		}
		else{}



	}


private:
	CNode* nleft;
	CNode* nright;

	int count;
};

class GrtrThenNode : public CNode
{
public:
	GrtrThenNode(CNode *left, CNode *right)  { nleft = left; nright = right;}

	~GrtrThenNode(){delete nleft; delete nright;}

	void CreateTree(){}


private:
	CNode* nleft;
	CNode* nright;

	int count;
};

class LessThenNode : public CNode
{
public:
	LessThenNode(CNode *left, CNode *right)  { nleft = left; nright = right;}

	~LessThenNode(){delete nleft; delete nright;}

	void CreateTree(){}


private:
	CNode* nleft;
	CNode* nright;

	int count;
};

class VariableNode : public CNode
{
public:
	VariableNode(const char *var, int val)  { Var = var; Val = val;}

	~VariableNode(){}

	void CreateTree(){}


private:
	const char *Var;
	int Val;

	CNode* nleft;
	CNode* nright;

	int count;
};

class AssignmentNode : public CNode
{
public:
	AssignmentNode(VariableNode *left,  CNode* right)   { nleft = left; nright = right;}

	~AssignmentNode(){}

	void CreateTree(){}


private:

	VariableNode* nleft;
	CNode* nright;
	int count;
};

class ExponentNode : public CNode
{
public:
	ExponentNode(CNode *left,  CNode *right)   { nleft = left; nright = right;}

	~ExponentNode(){}

	void CreateTree(){}


private:

	CNode* nleft;
	CNode* nright;
	int count;
};

class SqrRootNode : public CNode
{
public:
	SqrRootNode(CNode *left)   { nleft = left;}

	~SqrRootNode(){}

	void CreateTree(){}


private:

	CNode* nleft;
	CNode* nright;
	int count;
};

class ParenthesesNode : public CNode
{
public:
	ParenthesesNode(CNode* Express)   { Expression = Express;}

	~ParenthesesNode(){}

	void CreateTree(){}


private:

	CNode* Expression;
	int count;
};


class CNodeInt : public CNode
{
public:
	CNodeInt(int i) {val = i;}
	int &Value() {return val;}
//	virtual Val Evaluate() {}

private:
	int val;
};

class CNodeStr : public CNode
{
public:
	CNodeStr(const char *s) {val = s;}

//	virtual Val Evaluate() {return Val(val);}

private:
	std::string val;
};


class CNodeStmts : public CNode
{
public:
	CNodeStmts(CNode *left, CNode *right) {nleft = left;  nright = right;}
	virtual ~CNodeStmts() {delete nleft;  delete nright;}

	void Evaluate(){}

private:
	CNode *nleft;
	CNode *nright;
};

/*
class AddOperation : public CNode
{
public:
	CNodetree(CNode *a, CNodeStr *b, CNode *c) {pa = a; Action = b; pc = c;}

	virtual Val Evaluate()
	{       Val v = Action->Evaluate();
		Val(s);
//		if(v ='<')
		{
			Print(pa);
			Print(pc);
		}

		std::cout << std::endl;

		return Val();
	}


private:
	void Print(CNode *n)
	{
		Val v = n->Evaluate();
		if(v.GetType() == Val::INT)
			std::cout << v.IVal() << " ";
		else if(v.GetType() == Val::STR)
			std::cout << v.SVal() << " ";
	}

	CNode *pa;
	CNode *pc;
	CNodeStr *Action;
};
*/
/*
class CNodetree : public CNode

{

public:
	CNodetree(CNode *a, CNode *b) {pa = a;  pb = b;}

	virtual Val Evaluate()

	{
		for(int i=0;  i<1;  i++)
		{
			Print(pa);
			Print(pb);

		}

		std::cout << std::endl;


		return Val();
	}


private:

	void Print(CNode *n)
	{
		Val v = n->Evaluate();
		if(v.GetType() == Val::INT)
			std::cout << v.IVal() << " ";

		else if(v.GetType() == Val::STR)
			std::cout << v.SVal() << " ";
	}


	CNode *pa;
	CNode *pb;
};

class CPlusTree : public CNode
{
public:
	string stmtplus['+'];
	CPlusTree(CNode *a, CNode *b) {pa = a; pb = b;}
	virtual ~CPlusTree() {delete pa; delete pb; delete pc;}

	virtual Val Evaluate()
	{
		pa->Evaluate();
		pb->Evaluate();
		//pc->Evaluate();

		return Val();
	}

private:

	CNode *pa;
	CNode *pb;
	string *pc;
};

class CCompareTree : public CNode
{
public:
	CCompareTree(CNode *a, string comp1, CNode *c) {pa = a; comp = comp1; pc = c;}
	virtual ~CCompareTree() {delete pa; comp = ""; delete pc;}
	
	virtual Val Evaluate()
	{
		if(comp.compare("<")){}

	}


private:
	CNode *pa;
	string comp;
	CNode *pc;
};


class CNodeStmts : public CNode
{
public:
	CNodeStmts(CNode *a, CNode *b) {pa = a;  pb = b;}
	virtual ~CNodeStmts() {delete pa;  delete pb;}

	virtual Val Evaluate()
	{
		pa->Evaluate();
		pb->Evaluate();

		return Val();
	}

private:

	CNode *pa;
	CNode *pb;
};*/

#endif
