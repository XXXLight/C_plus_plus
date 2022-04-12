#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (sum < 0) sum = nums[i];
			else sum += nums[i];
			res = max(res, sum);
		}
		return res;
	}
};


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n);
		dp[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			res = max(res, dp[i]);
		}
		return res;
	}
};