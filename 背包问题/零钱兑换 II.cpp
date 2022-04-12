#include<bits/stdc++.h>
using namespace std;

// 这是组合问题，主要体现在 2 2 1和1 2 3属于一种情况
// 那个放外层？(coins)
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