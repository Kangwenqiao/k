#include<iostream>
using namespace std;
const int maxint = 1e6+10;
int n;
int pre[maxint];
void init()
{
	for (int i = 0; i < maxint; i++)
	{
		pre[i] = i;
	}
	return;
}
int find(int x)
{
	if (pre[x] == x)
		return x;
	else
		return find(pre[x]);
}
void un_ion(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		pre[fx] = fy;
}
int main()
{
  init();
	int a, b;
	cin >> a >> b;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		un_ion(x, y);
	}
	int sum = 0;
	for (int i = 1; i <= a * b; i++)
	{
		if (i == pre[i])
		{
			sum++;
		}
	}
	cout << sum;
}
