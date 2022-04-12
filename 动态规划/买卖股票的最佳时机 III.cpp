#include<bits/stdc++.h>
using namespace std;

// i��ʾ������k��ʾ���ױ�����0/1��ʾ������û�й�Ʊ��д�Ķ���Ҫȷ����һ��ʱ�仹�ܹ������ף�
//base case��
//dp[-1][k][0] = dp[i][0][0] = 0
//dp[-1][k][1] = dp[i][0][1] = -infinity
//
//״̬ת�Ʒ��̣�
//dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
//dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])

//  k=2
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int max_k = 2;
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2, 0))); //������ά����dp[n][max_k + 1][2]
		for (int i = 0; i < n; i++) {
			for (int k = max_k; k >= 1; k--) { //k�������������ԣ��ѳ���
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


// ������dp[][][]����ķ�������vector���ӷ���
//  ʹ��memset()������ʼ����ά����ʱҪǧ��С�ģ�
//	1.��ά������������memset()������ʼ��ʱ��ֻ�ܳ�ʼ��Ϊ0���� - 1�������ά���������ֵ��Ϊ�������
//	2.��άchar��������memset()������ʼ��ʱ�������ƣ��ɳ�ʼ��Ϊ�����ַ���
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int dp[n][3][2];
		memset(dp, 0, sizeof(dp));
		// ��0��1�ʽ�������û�й�Ʊ		����0  
		// ��0��1�ʽ��������й�Ʊ		���˵�0��Ĺ�Ʊ-prices[0]  
		// ��0��2�ʽ�������û�й�Ʊ		����0
		// ��0��2�ʽ��������й�Ʊ		���˵�0��Ĺ�Ʊ-prices[0]  
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