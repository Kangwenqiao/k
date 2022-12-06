#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define ture 1800
#define  maxsize 100
typedef enum status { succ, fall, uncreat }status;
typedef struct AMGraph
{
	char vexs[maxsize];
	int arcs[maxsize][maxsize];
	int vexsnum, arcsnum;
}AMGraph, * ptamg;

typedef struct closedge
{
	char adjvex;
	int lowcost;
}close[maxsize];

int location(char n, AMGraph& g)
{
	int i = 0;
	while (n != g.vexs[i])
	{

		if (g.vexs[i] == '\0')
		{
			exit(0);
		}
		i++;
	}
	return i;
}

status createudn(AMGraph& g)
{
	cin >> g.vexsnum >> g.arcsnum;
	int i, j;
	for (i = 0; i < g.vexsnum; i++)
	{
		cin >> g.vexs[i];
	}
	for (i = 0; i < g.vexsnum; i++)
		for (j = 0; j < g.vexsnum; j++)
			g.arcs[i][j] = maxsize;
	for (int k = 0; k < g.arcsnum; k++)
	{
		char v1, v2;
		int	w;
		cin >> v1 >> v2 >> w;
		i = location(v1, g), j = location(v2, g);
		g.arcs[i][j] = w;
		g.arcs[j][i] = g.arcs[i][j];
	}
	return succ;
}

int mini(close closeedege, AMGraph g)
{
	int i, j;
	int min = maxsize;
	for (int i = 0; i < g.arcsnum; i++)
	{
		if (closeedege[i].lowcost < min && closeedege[i].lowcost>0)
		{
			min = closeedege[i].lowcost;
			j = i;
		}
	}
	return j;
}

void ShortTestPath_dij(AMGraph g, int v0)
{
	int v; int S[maxsize], D[maxsize], path[maxsize]; int i, j, min, w;
	int n = g.vexsnum;
	for (v = 0; v < n; ++v)
	{
		S[v] = false;
		D[v] = g.arcs[v0][v];
		if (D[v] < maxsize) path[v] = v0;
		else path[v] = -1;
	}
	S[v0] = ture;
	D[v0] = 0;
	for (i = 1; i < n; ++i)
	{
		min = maxsize;
		for (w = 0; w < n; ++w)
			if (!S[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		S[v] = ture;
		for (w = 0; w < n; ++w)
			if (!S[w] && (D[v] + g.arcs[v][w] < D[w]))
			{
				D[w] = D[v] + g.arcs[v][w];
				path[w] = v;
			}
		
	}
	for (i = 0; i < 6; i++)
	{
		cout << D[i]<<" ";
	}
}

int main()
{
	AMGraph g;
	createudn(g);
	close c;
	ShortTestPath_dij(g, 0);
	return 0;
}
