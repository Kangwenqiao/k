#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
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
vector<bool> visit;
queue<int> list;
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
		visit.push_back(0);
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
int first(int n)
{
	return dian[n]->firnext->numpon;
}
int next(int n,int m)
{
	bian* p = new bian;
	p = dian[n]->firnext;
	while (p!=NULL)
	{
		if (p->numpon ==m && p->next != NULL)
		{
			return p->next->numpon;
		}
		p = p->next;
	}
	return -1;
}
void ALGbfs(ALgraph& g, int n)
{
	cout << dian[n]->data;
	visit[n] = 1;
	list.push(n);
	int w;
	while (!list.empty())
	{
		int u = list.front(); list.pop();
		for (w=first(u); w >= 0;w=next(u,w))
		{
			if (!visit[w])
			{
				cout << dian[w]->data; visit[w] = 1;
				list.push(w);
			}
		}
	}
}
int main()
{
	ALgraph *g = new ALgraph;
	creategraph(*g);
	ALGbfs(*g,0);
	return 0;
}