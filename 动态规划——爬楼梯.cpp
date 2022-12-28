#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
const int mod = 10007;
int dp[1010];
int main()
{
	int n;
	cin >> n;
	dp[1] = dp[0] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n] << endl;
	return 0;
}
