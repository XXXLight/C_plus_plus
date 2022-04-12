// 5件物品，背包容量为8
// 单个物品重量：3 5 1 2 2
//	单个物品价值：4 5 2 1 3
#include<bits/stdc++.h>
using namespace std;

const int maxN = 100;
const int maxV = 1000;
vector<int> w(maxN), c(maxN), dp(maxN);


//0 - 1 背包问题的 dp[N][V + 1] 解法
//dp[i][j]的含义是前0~i件物品，背包容量是j的情况下所能获得的最大价值
int maxValue01_1(int N, int V, vector<int>& v, vector<int>& w) {
	vector<vector<int>> dp(N, vector<int>(V + 1));
	dp[0][0] = 0;
	for (int i = 0; i < V + 1; i++) {
		// 只有第0件物品，背包容量是i，当i>=v[0]时表示可以放下第一件物品
		dp[0][i] = i >= v[0] ? w[0] : 0;
	}
	for (int i = 1; i < N; i++) {// 从1开始正向枚举N件物品
		for (int j = 0; j < V + 1; j++) {// 正向枚举背包容量，注意这里无论正向或者逆向枚举都可以，for (int j = V; j >=0; j--)也是可以的
			if (j >= v[i]) {
				dp[i][j] = w[i] + dp[i - 1][j - v[i]]; // 选择该物品
			}
			// 注意这里左边是dp[i-1][j],完全背包是dp[i][j]
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}
	return dp[N - 1][V];// 0~N-1件物品，背包容量是V时的最大价值
}


//0 - 1 背包问题的 dp[2][V + 1] 解法
int maxValue01_2(int N, int V, vector<int>& v, vector<int>& w) {
	vector<vector<int>> dp(2, vector<int>(V + 1));
	dp[0][0] = 0;
	for (int i = 0; i < V + 1; i++) {
		dp[0][i] = i >= v[0] ? w[0] : 0;
	}
	for (int i = 1; i < N; i++) {// 从1开始正向枚举N件物品
		for (int j = 0; j < V + 1; j++) {// 正向枚举背包容量
			int n = dp[(i - 1) % 2][j]; // 不选该物品
			int y = 0;
			if (j >= v[i]) {
				y = w[i] + dp[(i - 1) % 2][j - v[i]]; // 选择该物品
			}
			dp[i % 2][j] = max(n, y);
		}
	}
	return dp[(N - 1) % 2][V];
}


// 为什么要逆向枚举j的问题： https://blog.csdn.net/weixin_44176696/article/details/105209974
// 假设正向枚举，且当前处在第i层，j正向枚举的话用到的是第i行的数据，逆向枚举才是用到i-1行的数据
//0-1 背包问题的 dp[V + 1] 解法
int maxValue01_3(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < V + 1; i++) {
		dp[i] = i >= v[0] ? w[0] : 0;
	}
	for (int i = 1; i < N; i++) {// 从1开始正向枚举N件物品
		for (int j = V; j >= 0; j--) {// 逆向枚举背包容量
			if (j >= v[i]) {
				dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
			}

		}
	}
	return dp[V];
}


//0-1 背包问题的 dp[V + 1] 解法 简化（标准版）
int maxValue01_4(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// 从0开始正向枚举N件物品
		for (int j = V; j >= v[i]; j--) {// 逆向枚举背包容量
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}

int main() {
	int n, V;
	cin >> n >> V;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int v = 0; v <= V; v++) dp[v] = 0;
	for (int i = 1; i <= n; i++) {
		for (int v = V; v >= w[i]; v--) {
			dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
		}
	}
	int res = 0;
	for (int v = 0; v <= V; v++) {
		res = max(res, dp[v]);
	}
	cout << res << endl;
	cout << maxValue01_1(n, V, w, c) << endl;
	cout << maxValue01_2(n, V, w, c) << endl;
	cout << maxValue01_3(n, V, w, c) << endl;
	cout << maxValue01_4(n, V, w, c) << endl;
	return 0;
}






//	AC代码
#include<bits/stdc++.h>
using namespace std;
//	0-1 背包问题的 dp[V + 1] 解法 简化（标准版）
int maxValue01_4(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// 从0开始正向枚举N件物品
		for (int j = V; j >= v[i]; j--) {// 逆向枚举背包容量
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}

int main() {
	int N, V;
	cin >> N >> V;
	vector<int> vV(N);
	vector<int> vW(N);
	for (int i = 0; i < N; i++) cin >> vV[i] >> vW[i];
	cout << maxValue01_4(N, V, vV, vW);
	return 0;
}





//无优化版
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			f[i][j] = f[i - 1][j];
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}


