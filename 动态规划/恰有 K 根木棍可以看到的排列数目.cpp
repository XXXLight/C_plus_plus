#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	typedef long long LL;
	static const int N = 1010, MOD = 1e9 + 7;// 改成static const int 就不会报错
	int f[N][N];

	// 第一类斯特林数
	int rearrangeSticks(int n, int k) {
		f[0][0] = 1; // 空集是一种方案
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				f[i][j] = (f[i - 1][j - 1] + (LL)(i - 1) * (f[i - 1][j])) % MOD;
		return f[n][k];
	}
};
