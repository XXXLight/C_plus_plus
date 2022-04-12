#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) return nums[0];
		vector<int> help1(len), help2(len);
		// 学会这种拷贝数组的方法
		copy(nums.begin() + 1, nums.end(), help1.begin());
		copy(nums.begin(), nums.end() - 1, help2.begin());
		int r1 = rob1(help1);
		int r2 = rob1(help2);
		return max(r1, r2);
	}
	int rob1(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) return nums[0];
		vector<int> dp(len);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < len; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[len - 1];
	}
};