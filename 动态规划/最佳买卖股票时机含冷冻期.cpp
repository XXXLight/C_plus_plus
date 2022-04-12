#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0 || n == 1) return 0;
		vector<vector<int>> dp(n, vector<int>(2, 0));
		// 用公式求解即可
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		dp[1][0] = max(0, prices[1] - prices[0]);
		dp[1][1] = max(-prices[0], -prices[1]);
		for (int i = 2; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
		}
		return dp[n - 1][0];
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		int dp_pre_0 = 0; // 代表 dp[i-2][0]
		for (int i = 0; i < n; i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
			dp_pre_0 = temp;
		}
		return dp_i_0;
	}
};