#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
typedef struct bian//边结点
{
	int numpon;
	struct bian* next;
}bian;
typedef struct jiedian//顶点
{
	char data;
	struct bian* firnext;
}jiedian;
typedef struct ALgraph
{
	struct jiedian* jex;
	int vexnum,arcnum;
}ALgraph;
vector<jiedian*> dian;
vector<jiedian*>::iterator start;
vector<jiedian*>::iterator finish;
int location(vector<jiedian*>::iterator start, vector<jiedian*>::iterator end,char a)
{
	jiedian* p = new jiedian;
	for (int i=0; start != finish; start++,i++)
	{
		p = *start;
		if (p->data == a)
		{
			return i;
		}
	}
	exit(1);
}
void creategraph(ALgraph &g)
{
	cin >> g.vexnum >> g.arcnum;
	for (int k = 0;k<g.vexnum;++k)
	{
		jiedian* p = new jiedian;
		cin >> p->data;
		p->firnext = NULL;
		dian.push_back(p);
	}
	start = dian.begin(); finish = dian.end();
	for (int k = 0; k < g.arcnum; ++k)
	{
		char v1, v2; int i, j;
		cin >> v1 >> v2;
		i = location(start,finish,v1), j = location(start,finish,v2);
		

        bian* p1=new bian;
		p1->numpon = j;
		p1->next = dian[i]->firnext; dian[i]->firnext = p1;

		bian* p2 = new bian;
		p2->numpon = i;
		p2->next = dian[j]->firnext; dian[j]->firnext = p2;

	}
	cout << "NO WARNING" << endl;
}
int main()
{
	ALgraph *g = new ALgraph;
	creategraph(*g);
}