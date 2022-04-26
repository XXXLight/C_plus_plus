#include<bits/stdc++.h>
using namespace std;

//多重背包问题的常规解法
// 输入:N种物品	 背包容量V  第 i 种物品最多有 s[i] 件，每件体积是 v[i]，价值是 w[i]。
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {	// 枚举物品种类
		for (int j = V; j >= v[i]; j--) {	// 枚举背包容量
			for (int k = 0; k <= s[i] && j >= k * v[i]; k++) {
				dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
			}
		}
	}
	return dp[V];
}


//多重背包问题的「二进制优化」解法
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	// 扁平化
	vector<int> worth, volume;
	// 我们希望每件物品都进行扁平化，所以首先遍历所有的物品
	for (int i = 0; i < N; i++) {
		// 获取每件物品的出现次数
		int val = s[i];
		// 进行扁平化：如果一件物品规定的使用次数为 7 次，我们将其扁平化为三件物品：1*重量&1*价值、2*重量&2*价值、4*重量&4*价值
		// 三件物品都不选对应了我们使用该物品 0 次的情况、只选择第一件扁平物品对应使用该物品 1 次的情况、只选择第二件扁平物品对应使用该物品 2 次的情况，只选择第一件和第二件扁平物品对应了使用该物品 3 次的情况 ... 
		for (int k = 1; k <= val; k *= 2) {
			val -= k;
			worth.push_back(w[i] * k);
			volume.push_back(v[i] * k);
		}
		if (val > 0) {
			worth.push_back(w[i] * val);
			volume.push_back(v[i] * val);
		}
	}
	
	// 0-1 背包问题解决方案
	vector<int> dp(V + 1);
	for (int i = 0; i < worth.size(); i++) {
		for (int j = V; j >= volume[i]; j--) {
			dp[j] = max(dp[j], dp[j - volume[i]] + worth[i]);
		}
	}
	return dp[V];
}


//多重背包问题的「单调队列」解法
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	vector<int> g(V + 1);// 辅助队列，记录的是上一次的结果
	vector<int> q(V + 1);// 主队列，记录的是本次的结果

	// 枚举物品
	for (int i = 0; i < N; i++) {
		int vi = v[i];
		int wi = w[i];
		int si = s[i];
		// 将上次算的结果存入辅助数组中
		g = dp;

		// 枚举余数
		for (int j = 0; j < vi; j++) {
			int hh = 0, tt = -1;
			// 枚举同一余数情况下，有多少种方案。例如余数为 1 的情况下有：1、vi + 1、2 * vi + 1、3 * vi + 1 ...
			for (int k = j; k <= V; k += vi) {
				dp[k] = g[k];
				if (hh <= tt && q[hh] < k - si * vi) hh++;
				if (hh <= tt) dp[k] = max(dp[k], g[q[hh]] + (k - q[hh]) / vi * wi);
				while (hh <= tt && g[q[tt]] - (q[tt] - j) / vi * wi <= g[k] - (k - j) / vi * wi) tt--;
				q[++tt] = k;
			}
		}
	}
	return dp[V];
}




// 朴素版本
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
			for (int k = 0; k <= s[i] && k*v[i] <= j; k++) {
				// k=0时包含f[i-1][j]
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
