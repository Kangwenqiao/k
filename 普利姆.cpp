#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define  maxsize 100
typedef enum status{succ,fall,uncreat}status;
typedef struct AMGraph
{
	char vexs[maxsize];
	int arcs[maxsize][maxsize];
	int vexsnum, arcsnum;
}AMGraph,*ptamg;

typedef struct closedge
{
	char adjvex;
	int lowcost;
}close[maxsize];

int location(char n, AMGraph& g)
{
	int i=0;
	while (n != g.vexs[i])
	{
		
		if (g.vexs[i]=='\0')
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

int mini(close closeedege,AMGraph g)
{
	int i,j;
	int min=maxsize;
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

void MiniSpanTree_prim(AMGraph g, char u,close closeedge)
{
	int k;//locat
	k = location(u, g);
	int i, j;
	for (j = 0; j < g.vexsnum; j++)
	{
		if (j != k)
		{
			closeedge[j].adjvex = u;
			closeedge[j].lowcost = g.arcs[k][j];
		}
	}
	closeedge[k].lowcost = 0;
	for (i = 1; i < g.vexsnum; i++)
	{
		k = mini(closeedge,g);
		char u0;
		u0 = closeedge[k].adjvex;
		char v0 = g.vexs[k];
		cout << u0 <<" " << v0 << endl;
		closeedge[k].lowcost = 0;
		for (j = 0; j < g.vexsnum; j++)
			if (g.arcs[k][j] < closeedge[j].lowcost)
				closeedge[j] = { g.vexs[k],g.arcs[k][j] };
	}
}

int main()
{
	AMGraph g ;
	createudn(g);
	close c;
	MiniSpanTree_prim(g,'1',c);
	return 0;
}
