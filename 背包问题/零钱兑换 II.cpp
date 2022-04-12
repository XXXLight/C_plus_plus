#include<bits/stdc++.h>
using namespace std;

// ����������⣬��Ҫ������ 2 2 1��1 2 3����һ�����
// �Ǹ�����㣿(coins)
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1);
		dp[0] = 1;
		for (auto e : coins) {
			for (int i = 0; i <= amount; i++) {
				if (i - e >= 0) dp[i] += dp[i - e];
			}
		}
		return dp[amount];
	}
};