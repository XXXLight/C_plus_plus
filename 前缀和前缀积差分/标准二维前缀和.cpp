#include<iostream>
#include<cstring>
using namespace std;
int dp[2000][2000], map[2000][2000];

//https://blog.csdn.net/qq_34990731/article/details/82807870
int main()
{
	int m, n, k;//�����ľ�����n*m��,��k���ѯ 
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)//Ԥ����һ�� 
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
	for (int i = 1; i <= k; i++)//���ܲ�ѯ 
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1]) << endl;//O��1����ѯ 
	}
	return 0;
}
