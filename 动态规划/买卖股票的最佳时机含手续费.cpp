#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			if (i - 1 == -1) {
				dp[i][0] = 0;
				dp[i][1] = -prices[i] - fee; //改动地方
				continue;
			}
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee); //改动地方
		}
		return dp[n - 1][0];
	}
};