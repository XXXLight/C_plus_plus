#include<bits/stdc++.h>
using namespace std;

int maxValue(int N, int V, int M, vector<int>& v, vector<int>& m, vector<int>& w) {
	vector<vector<int>> dp(V+1, vector<int>(M + 1));
	for (int i = 0; i < N; i++) {
		for (int j = V; j >= v[i]; j--) {
			for (int k = M; k >= m[i]; k--) {
				dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + w[i]);
			}
		}
	}
	return dp[V][M];
}



#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int v[N], w[N], s[N];
int f[N][N];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
	for (int i = 1; i <= n; i++) {//枚举背包
		for (int j = 1; j <= m; j++) {//枚举体积
			for (int k = 0; k <= s[i]; k++) {
				if (j >= k * v[i]) {
					f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
				}
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}

