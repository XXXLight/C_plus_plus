#include<bits/stdc++.h>
using namespace std;

//�Ƽ��ⷨ����ͼ��

//base case��
//dp[-1][k][0] = dp[i][0][0] = 0
//dp[-1][k][1] = dp[i][0][1] = -infinity
//
//״̬ת�Ʒ��̣���ǰһ���л�û��0/1��
//dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
//dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])

// ҲҪע��k�ı仯

// k=1
// ֱ��д��
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			if (i - 1 == -1) {
				dp[i][0] = 0;
				// dp[i][0]=dp[0][0]=max(dp[-1][0],dp[-1][1]+prices[0])=max(0,-infinity)=0
				dp[i][1] = -prices[i];
				// dp[i][1]=dp[0][1]=max(dp[-1][1],dp[-1][0]-prices[0])=max(-infinity,0-prices[0])=-prices[0]
				continue;
			}
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], -prices[i]);
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
			dp[i][1] = max(dp[i - 1][1], -prices[i]);
		}
		return dp[n - 1][0];
	}
};
// ״̬ѹ��
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		for (int i = 0; i < n; i++) {
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, -prices[i]);
		}
		return dp_i_0;
	}
};

// ��ͼ�����ν��
// ά����ֹ��ǰ����Сֵ���Ϳ��������ֹ��ǰ�������������󼴿�
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int res = 0;
		int curMin = prices[0];
		for (int i = 1; i < n; i++) {
			curMin = min(curMin, prices[i]);
			res = max(res, prices[i] - curMin);
		}
		return res;
	}
};