#include<bits/stdc++.h>
using namespace std;


const int N = 1010, MOD = 1e9 + 7;
class Solution {
public:
	int f[N][N], s[N][N];
	int kInversePairs(int n, int k) {
		for (int i = 0; i <= n; i++)
			f[i][0] = s[i][0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++)
				s[i - 1][j] = (s[i - 1][j - 1] + f[i - 1][j]) % MOD;
			for (int j = 1; j <= k; j++) {
				if (i > j)
					f[i][j] = s[i - 1][j];
				else
					f[i][j] = (s[i - 1][j] - s[i - 1][j - i]) % MOD;
			}
		}
		int ans = f[n][k];
		ans = (ans + MOD) % MOD;
		return ans;
	}
};

