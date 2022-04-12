#include<bits/stdc++.h>
using namespace std;

int maxValue(int N, int V, vector<int>& S, vector<vector<int>>& v, vector<vector<int>>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {
		auto vol = v[i];
		auto wor = w[i];
		int si = S[i];
		for (int j = V; j >= 0; j--) {
			for (int k = 0; k < si; k++) {
				if (j >= vol[k]) {
					dp[j] = max(dp[j], dp[j - vol[k]] + wor[k]);
				}
			}
		}
	}
	return dp[V];
}
