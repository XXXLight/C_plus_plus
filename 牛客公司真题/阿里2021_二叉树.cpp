//dp[n][m] 总数为n 高度最大为m
#include<vector>
#include<iostream>
using namespace std;
long dp[55][55];
int kmod = 1e9 + 7;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m; i++)
		dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < i; k++)
			{
				//左树k个节点，右树i-k-1个节点，且左右子树都要求小于等于j-1
				dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1] % kmod;
				dp[i][j] %= kmod;
			}
	cout << dp[n][m] << endl;
	return 0;
}
