#include<bits/stdc++.h>
using namespace std;


const int maxn = 2010;
bool dp[maxn][maxn];

class Solution {
public:
	bool checkPartitioning(string s) {
		memset(dp, 0, sizeof(dp));
		int n = s.length();
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
			if (i < n - 1) {
				if (s[i] == s[i + 1])dp[i][i + 1] = 1;
			}
		}
		for (int L = 3; L <= n; L++) {
			for (int i = 0; i + L - 1 < n; i++) {
				int j = i + L - 1;
				if (s[i] == s[j] && dp[i + 1][j - 1]) {
					dp[i][j] = 1;
				}
			}
		}
		for (int s = 1; s <= n - 2; s++)
			for (int e = s; e <= n - 2; e++)
				if (dp[0][s - 1] && dp[s][e] && dp[e + 1][n - 1])
					return true;
		return false;
	}
};

