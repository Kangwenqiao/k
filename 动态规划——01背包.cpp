#include <iostream>
using namespace std;
#define maxint 100
#define max(x,y) x>y?x:y
int dp[100][100];
int weight[3] = { 1,3,4 }, value[3] = {15,20,30};
void bag()
{
	int i, j;
	//初始化
	for (i = 0; i < 3; i++)//先全部置0
	{for (j = 0; j < 3; j++) dp[i][j] = 0;}
	for (j = 4; j > 0; j--)
	{
		if (weight[0] <= j)
		{
			dp[0][j] = value[0];
		}
	}
	for (i = 1; i <= 2; i++)
	{
		for (j = 4; j > 0; j--)
		{
			if (j >=weight[i])//可以放下
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]]+ value[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 4; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}
int main()
{
	bag();
	return 0;
}
