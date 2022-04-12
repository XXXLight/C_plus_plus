#include<bits/stdc++.h>
using namespace std;

int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> worth, volume;
	for (int i = 0; i < N; i++) {
		int type = s[i];
		if (type > 0) { // 将多重背包问题转换为 0-1 背包问题
			for (int k = 1; k <= type; k *= 2) {
				type -= k;
				worth.push_back(w[i] * k);
				volume.push_back(v[i] * k);
			}
			if (type > 0) {
				worth.push_back(w[i] * type);
				volume.push_back(v[i] * type);
			}
		}
		else if (type == -1) {
			worth.push_back(w[i]);
			volume.push_back(v[i]);
		}
		else { // 对于完全背包，将 worth 翻转，用作标记
			worth.push_back(-w[i]);
			volume.push_back(v[i]);
		}
	}

	vector<int> dp(V + 1);
	for (int i = 0; i < worth.size(); i++) {
		int wor = worth[i];
		int vol = volume[i];
		if (wor < 0) { // 完全背包问题
			for (int j = vol; j <= V; j++) {
				dp[j] = max(dp[j], dp[j - vol] - wor); // 将 worth 重新翻转为正整数
			}
		}
		else { // “原 0-1 背包物品” 或 “由多重背包转移过来的 0-1 背包问题”
			for (int j = V; j >= vol; j--) {
				dp[j] = max(dp[j], dp[j - vol] + wor);
			}
		}
	}
	return dp[V];
}
