#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		// 边界处都是1
		vector<vector<int>> dp(m, vector<int>(n, 1));
		// 遍历方法：逐行，从左到右
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp.back().back();
	}
};


class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m > n) {
			return uniquePaths(n, m);
		}
		long long ret = 1;
		for (int x = n, y = 1; y < m; ++x, ++y) {
			// 不要写成 ret *= x / y ，因为 x / y 不一定是整数但是会被取整，但 ret * x / y 一定为整数
			ret = ret * x / y;
		}
		return ret;
	}
};

