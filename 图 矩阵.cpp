#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define maxint 32767
#define mvmun 100
typedef char vertextype;
typedef int arctype;
typedef struct
{
	vertextype vexs[mvmun];
	arctype arcs[mvmun][mvmun];
	int vexnum, arcnum;
}amgraph;
int location(amgraph& g, vertextype num)
{
	for(int i=0;i<g.vexnum;++i)
	{
		if (num == g.vexs[i])
		{
			return i;
		}
	}
	exit(0);
}
void createund(amgraph& g)
{
	int i, j;
	cin >> g.vexnum >> g.arcnum;
	for ( i = 0; i < g.vexnum; ++i)
		cin >> g.vexs[i];
	for ( i = 0; i < g.vexnum; ++i)
		for (int j = 0; j < g.vexnum; ++j)
			g.arcs[i][j] = 0;

	for (int k = 0; k < g.arcnum; ++k)
	{
		vertextype v1, v2;
		arctype w;
		cin >> v1 >> v2>>w;
		i = location(g, v1); j = location(g, v2);
		g.arcs[i][j] = w;
		g.arcs[j][i] = g.arcs[i][j];
	}
}
void print(amgraph &g)
{
	int i, j;
	for (i = 0; i < g.arcnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
		{
			cout << g.arcs[i][j]<<" ";
		}
		printf("\n");
	}
}
int main()
{
	amgraph g;
	createund(g);
	print(g);
	return 0;
}
