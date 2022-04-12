#include<bits/stdc++.h>
using namespace std;

// i表示天数；k表示交易笔数；0/1表示手上有没有股票（写的东西要确保过一段时间还能够看明白）
//base case：
//dp[-1][k][0] = dp[i][0][0] = 0
//dp[-1][k][1] = dp[i][0][1] = -infinity
//
//状态转移方程：
//dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
//dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])

//  k=2
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int max_k = 2;
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2, 0))); //本质三维数组dp[n][max_k + 1][2]
		for (int i = 0; i < n; i++) {
			for (int k = max_k; k >= 1; k--) { //k正反遍历都可以，已尝试
				if (i - 1 == -1) {
					dp[i][k][0] = 0;
					dp[i][k][1] = -prices[i];
					continue; 
				}
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
			}
		}
		return dp[n - 1][max_k][0];
	}
};


// 用这种dp[][][]数组的方法比用vector更加方便
//  使用memset()函数初始化二维数组时要千万小心：
//	1.二维整型数组利用memset()函数初始化时，只能初始化为0或者 - 1，否则二维整型数组的值将为随机数。
//	2.二维char数组利用memset()函数初始化时不受限制，可初始化为任意字符。
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int dp[n][3][2];
		memset(dp, 0, sizeof(dp));
		// 第0天1笔交易手上没有股票		利润0  
		// 第0天1笔交易手上有股票		买了第0天的股票-prices[0]  
		// 第0天2笔交易手上没有股票		利润0
		// 第0天2笔交易手上有股票		买了第0天的股票-prices[0]  
		dp[0][1][0] = 0, dp[0][1][1] = -prices[0];
		dp[0][2][0] = 0, dp[0][2][1] = -prices[0];
		for (int i = 1; i < n; i++) {
			for (int k = 1; k <= 2; k++) {
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
			}
		}
		return dp[n - 1][2][0];
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int dp_i10 = 0, dp_i11 = INT_MIN;
		int dp_i20 = 0, dp_i21 = INT_MIN;
		for (int price : prices) {
			dp_i20 = max(dp_i20, dp_i21 + price);
			dp_i21 = max(dp_i21, dp_i10 - price);
			dp_i10 = max(dp_i10, dp_i11 + price);
			dp_i11 = max(dp_i11, -price);
		}
		return dp_i20;
	}
};