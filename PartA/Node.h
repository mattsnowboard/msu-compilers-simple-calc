#ifndef _NODE_H
#define _NODE_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <list>
#include <vector>
#include <map>

using namespace std;


class CNode
{
public:

	CNode(void) {}
	virtual ~CNode(void) {}
	virtual void Evaluate() {}
	enum Type {NONE, INT, STR};
	CNode* Parent, *Child;
	vector <int> CalcVector;
	map<string,int> CalcMap;
	map<string,int> Variables;


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
		{
		 if (nright->IVal() == 0) 
			{cout << "Can't divided by 0!" << endl; return 0;}
		else
		{
			int x = nleft->IVal();
			int y = nright->IVal();
			int z = x+y;
			return z;
			}
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
	virtual bool Calculate()
	{
		bool LGrtrThenR = false;

		if((nleft->GetType() & nright->GetType()) == INT)
		{
			int x = nleft->IVal();
			int y = nright->IVal();
			if (x > y)
			{ LGrtrThenR =true;}
			return LGrtrThenR;				 
		}
		else{}
	}


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

	virtual bool Calculate()
	{
		bool LLessThenR = false;

		if((nleft->GetType() & nright->GetType()) == INT)
		{
			int x = nleft->IVal();
			int y = nright->IVal();
			if (x < y)
			{ LLessThenR = true;}
			return LLessThenR;				 
		}
		else{}



	}


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

	virtual int Calculate()
	{		
		Variables.insert(pair<const char*,int>(Var,Val) );
	}


private:
	const char *Var;
	int Val;

	map<const char*,int> Variables;


	int count;
};

class AssignmentNode : public CNode
{
public:
	AssignmentNode(VariableNode *left,  CNode* right)   { nleft = left; nright = right;}

	~AssignmentNode(){}

	void CreateTree(){}

	virtual int Calculate()
	{		
		if((nleft->GetType() == STR) & (nright->GetType() == INT))
		{
			string temp = nleft->SVal();
			const char* x = temp.c_str();
			int y = nright->IVal();
			Variables.insert(pair<const char*,int>(x,y) );
		}
		else if((nleft->GetType() == INT) & (nright->GetType() == STR))
		{
			string temp = nright->SVal();
			const char* y = temp.c_str();
			int x = nleft->IVal();
			Variables.insert(pair<const char*,int>(y,x) );
		}
	}
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
	virtual int Calculate()
	{
		
		if((nleft->GetType() & nright->GetType()) == INT)
		{
			int x = nleft->IVal();
			int y = nright->IVal();
		      	if( y == 0) { return 1;}

			else{
				for (int i = 0; i<y; i++)
				{
					NodeResult = x*x;
				}
				CalcVector.push_back(NodeResult);
				return NodeResult;
			}
		}
	}


private:

	CNode* nleft;
	CNode* nright;
	int NodeResult;
};

class SqrRootNode : public CNode
{
public:
	SqrRootNode(CNode *left)   { nleft = left;}

	~SqrRootNode(){}

	void CreateTree(){}
	virtual int Calculate()
	{
		
		if(nleft->GetType() == INT)
		{
			int x = nleft->IVal();
			NodeResult = x ^(-1/2);	
			CalcVector.push_back(NodeResult);
			return NodeResult;		
			
		}
	}


private:

	CNode* nleft;
	CNode* nright;
	int NodeResult;
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
	void CreateTree(){
		CalcVector.push_back(val);
	}
private:
	int val;
};

class CNodeStr : public CNode
{
public:
	CNodeStr(const char *s) {val = s;}

	void CreateTree(){
		//CalcVector.push_back(val);
	}

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

#endif
