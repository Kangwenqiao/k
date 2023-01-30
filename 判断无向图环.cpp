#include <iostream>
#include<queue>
#include<vector>
using namespace std;
#define maxint 1000000
int g[maxint];
vector<int> a[maxint];
int n;
int main()
{
    cin >> n;
    int u, v;
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> u >> v;
        g[u]++; g[v]++;
        a[u].push_back(v);//
        a[v].push_back(u);
    }
    queue<int> q;
    for (i = 1; i <= n; i++)
        if (g[i] == 1) q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (i = 0; i < a[x].size(); i++)
        {
            g[a[x][i]]--;
            if (g[a[x][i]] == 1)
                q.push(a[x][i]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (g[i] > 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}
