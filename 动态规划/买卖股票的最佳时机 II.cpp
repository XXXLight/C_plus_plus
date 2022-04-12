#include<bits/stdc++.h>
using namespace std;

//base case：
//dp[-1][k][0] = dp[i][0][0] = 0
//dp[-1][k][1] = dp[i][0][1] = -infinity
//
//状态转移方程：
//dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
//dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])

// k=inf
// 直接写法
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			if (i - 1 == -1) {
				dp[i][0] = 0;
				dp[i][1] = -prices[i];
				continue;
			}
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); //与第一题相比只有dp[i-1][0]!=0罢了，加上就行了
		}
		return dp[n - 1][0];
	}
};


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); //与第一题相比只有dp[i-1][0]!=0罢了，加上就行了
		}
		return dp[n - 1][0];
	}
};

// 状态压缩
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		for (int i = 0; i < n; i++) {
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_i_0 - prices[i]);
		}
		return dp_i_0;
	}
};

// 画图
// 贪心，相邻的两天
class Solution {
public:
	int res = 0;
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		for (int i = 1; i < n; i++) {
			if (prices[i] > prices[i - 1])
				res += prices[i] - prices[i - 1];
		}
		return res;
	}
};