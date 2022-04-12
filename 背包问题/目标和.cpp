#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int cnt = 0;
	void backtrack(vector<int>&nums, int target, int depth, int sum) {
		if (depth == nums.size()) {
			if (sum == target) cnt++;
		}
		else {
			backtrack(nums, target, depth + 1, sum - nums[depth]);
			backtrack(nums, target, depth + 1, sum + nums[depth]);
		}
	}
	int findTargetSumWays(vector<int>& nums, int target) {
		backtrack(nums, target, 0, 0);
		return cnt;
	}
};