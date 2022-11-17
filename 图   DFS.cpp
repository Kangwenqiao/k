#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
typedef char vertextpyte;
typedef int arctype;
int point, arc;
vector<bool> visit;
typedef struct Arcnode//边结点
{
	int adjvex;
	struct Arcnode* next;
	
}ARCnode;
typedef struct VNode//顶点信息
{
	vertextpyte data;
	ARCnode* fiirstarc;
}VNode;
typedef struct//邻接表
{
	VNode* vertices;
	int vexnum, arcnum;
}ALGraph;
typedef enum Status {ok,no,uncreate}Status;
vector<VNode*> dian;
vector<VNode*>::iterator start;
vector<VNode*>::iterator finish;
int Location(vector<VNode*>::iterator start , vector<VNode*>::iterator end , char a)
{
	
	int i=0;
	for (; start != end; start++,i++)
	{
		VNode* d = *start;
		if (d->data == a)
		{
			return i;
		}
	}
	exit(1);
}
Status createudg(ALGraph &g)
{
	int i;
	cin >> g.vexnum >> g.arcnum;
	for (int i = 0; i < g.vexnum; ++i)
	{
		VNode* d = new VNode;
		cin >> d->data, d->fiirstarc = NULL;
		visit.push_back(0);
		dian.push_back(d);
	}
	 start=dian.begin(); finish=dian.end();
	for (int k = 0; k < g.arcnum; ++k)
	{
		char v1, v2; int j;
		cin >> v1 >> v2;
		i = Location(start,finish, v1), j = Location(start,finish, v2);
		ARCnode* p1 = new ARCnode;
		p1->adjvex = j;
		p1->next = start[i]->fiirstarc; start[i]->fiirstarc = p1;
		ARCnode* p2 = new ARCnode;
		p2->adjvex = i;
		p2->next = start[j]->fiirstarc; start[j]->fiirstarc = p2;
	}
	cout << "成功" << endl;
	return ok;
	
}
void DFS_AL(ALGraph &g, int v)//为访问第V个顶点
{
	visit[v] = 1;
	VNode *p;
	p = start[v];
	cout << p->data;
	while (p->fiirstarc!=NULL)
	{
		int w;
		w = p->fiirstarc->adjvex;
		if (!visit[w]) DFS_AL(g, w);
		p->fiirstarc = p->fiirstarc->next;
	}
}
int main()
{
	ALGraph* g=new ALGraph;
	createudg(*g);
	DFS_AL(*g,0);
	return 0;
}