#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef struct bitnode {
	int data;
	struct bitnode* lchild, * rchild;
}bitnode,*bitree;
void createbitree(bitree& t)
{
	char ch;
	cin >> ch;
	if (ch == '#')t = NULL;
	else
	{
		t = new bitnode;
		t->data = ch;
		createbitree(t->lchild);
		createbitree(t->rchild);
	}

}
void copy(bitree t, bitree& newt)
{
	if (t == NULL)
	{
		newt = NULL;
		return;
	}
	else
	{
		newt = new bitnode;
		newt->data = t->data;
		copy(t->lchild, newt->lchild);
		copy(t->rchild, newt->rchild);
	}
}
void inordertraverse(bitree& t)
{
	if (t)
	{
		inordertraverse(t->lchild);
		cout << t->data;
		inordertraverse(t->rchild);
	}
}
int depth(bitree& t)
{
	if (t == NULL) return 0;
	else
	{
		int m, n;
		m = depth(t->lchild);
		n = depth(t->rchild);
		if (m > n) return (m + 1);
		else return (n + 1);
	}
}
