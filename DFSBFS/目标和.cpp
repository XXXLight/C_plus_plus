#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		return dfs(nums, S, 0);
	}

	int dfs(vector<int> &nums, long long target, int depth) {
		if (target == 0 && depth == nums.size()) return 1;
		if (depth >= nums.size()) return 0;
		int ans = 0;
		ans += dfs(nums, target - nums[depth], depth + 1);
		ans += dfs(nums, target + nums[depth], depth + 1);
		return ans;
	}
};

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		return dfs(nums, S, 0);
	}
	int dfs(vector<int> &nums, long long target, int depth) {
		if (target == 0 && depth == nums.size()) return 1;
		if (depth >= nums.size()) return 0;
		return dfs(nums, target - nums[depth], depth + 1) + dfs(nums, target + nums[depth], depth + 1);
	}
};