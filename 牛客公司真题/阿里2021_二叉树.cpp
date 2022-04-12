//dp[n][m] ����Ϊn �߶����Ϊm
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
				//����k���ڵ㣬����i-k-1���ڵ㣬������������Ҫ��С�ڵ���j-1
				dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1] % kmod;
				dp[i][j] %= kmod;
			}
	cout << dp[n][m] << endl;
	return 0;
}
