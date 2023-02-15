#define _CRT_SECURE_NO_WARNINGS//dfs与bfs算法对于迷宫而言最先找到的路径必然是最短的
#include<iostream>
#include<stdio.h>
using namespace std;

int m, n, MIN = 99999;
int a[100][100] = { 0 }, vis[100][100] = { 0 };
int dir[4][2] = { 0,1,0,-1,-1,0,1,0 };
int s1[100][2] = { 0 }, s2[100][2] = { 0 };
void dfs(int x, int y, int sum) {
    if (sum > MIN) return;
    if (x == m && y == n) {
        for (int i = 0; i < 100; i++) {
            if (s1[i][0] == -1 && s1[i][1] == -1)
                break;
            s2[i][0] = s1[i][0];
            s2[i][1] = s1[i][1];
        }
        MIN = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx <= 0 || yy <= 0 || xx > m || yy > n) {
            continue;
        }
        if (!vis[xx][yy] && a[xx][yy] == 0) {
            s1[sum][0] = xx;
            s1[sum][1] = yy;
            vis[xx][yy] = 1;
            dfs(xx, yy, sum + 1);
            vis[xx][yy] = 0;
        }
    }
    return;
}
int main() {
    while (1) {
        cin >> m >> n;
        if (m == -1)return 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(s1, -1, sizeof(s1));
        memset(s2, -1, sizeof(s2));
        vis[1][1] = 1;
        MIN = 99999;
        dfs(1, 1, 0);
        if (MIN == 99999) {
            cout << "NO FOUND" << endl;
        }
        /*else {
            printf("1,1\n");
            for (int i = 0; i < MIN; i++) {
                printf("%d,%d\n", s2[i][0], s2[i][1]);
            }
            printf("\n");
        }*/

    }
   
    return 0;
}
