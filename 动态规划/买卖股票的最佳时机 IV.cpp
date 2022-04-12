#include<bits/stdc++.h>
using namespace std;

// k = any integer
class Solution {
public:
	//һ�ν�����������������ɣ�������Ҫ���졣����˵��Ч������ k Ӧ�ò����� n / 2�����������
	//��û��Լ�������ˣ��൱�� k = +infinity�����������֮ǰ������ġ�
	int maxProfit_k_inf(vector<int>& prices) {
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
	int maxProfit(int max_k, vector<int>& prices) {
		int n = prices.size();
		if (max_k > n / 2)
			return maxProfit_k_inf(prices);
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
		for (int i = 0; i < n; i++) {
			for (int k = max_k; k >= 1; k--) {
				if (i - 1 == -1) {
					//i==0ʱ��׼��ʽ
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