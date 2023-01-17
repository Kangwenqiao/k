#include<iostream>
#include<queue>
using namespace std;
int maze[101][101] = { 0 };
int path[101][101] ={0};
int cx[1, -1, 0, 0], cy[0, 0, -1, 1];
struct point
{
	int x, y;
	int step;
};
queue<point> r;
int main()
{
	int startx, starty,endx,endy;
	int n, m,flag=0;
	cin >> m >> n;
	int i, j;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++) cin >> maze[i][j];
	point start;
	cin >> startx >> starty >> endx >> endy;


	start.x = startx, start.y = starty, start.step = 0;
	path[startx][starty] = 1;

	r.push(start);
	while (!r.empty())
	{
		int x = r.front().x;
		int y = r.front().y;
		if (x == endx && y == endy)//判断是否到达终点
		{
			flag = 1;
			cout << r.front().step;
			break;
		}
		for (int k = 0; k < 4; k++)//走四个方向
		{
			int tmpx, tmpy;
			tmpx = r.front().x + cx[k];
			tmpy = r.front().y + cy[k];
			if (maze[tmpx][tmpy] == 1 && path[tmpx][tmpy] == 0)//maze代表迷宫有1代表可走，path代表路径1代表走过
			{
				point tmp;
				tmp.x = tmpx;
				tmp.y = tmpy;
				tmp.step = r.front().step + 1;
				r.push(tmp);
				path[tmpx][tmpy] = 1;
			}
		}
		r.pop();
	}
	if (flag == 0)//走不通情况
	{
		cout << "-1";

	}
	return 0;
}
