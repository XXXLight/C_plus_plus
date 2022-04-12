#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int constrainedSubsetSum(vector<int>& nums, int k) {
		vector<int>dp(nums.size(), 0);
		dp[0] = nums[0];
		int ans = dp[0];
		deque<int> sta;
		sta.push_back(0);
		for (int i = 1; i < nums.size(); i++)
		{
			dp[i] = max(dp[sta.front()] + nums[i], nums[i]);
			ans = max(ans, dp[i]);
			if (i - sta.front() == k) sta.pop_front();
			while (!sta.empty() && dp[sta.back()] < dp[i]) sta.pop_back();
			sta.push_back(i);
		}
		return ans;
	}
};

