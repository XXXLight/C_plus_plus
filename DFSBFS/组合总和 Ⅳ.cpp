#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.size() == 0 && target > 0) return 0;
		vector<int> memo(target + 1, -1);
		return  tryCombinationSum4(nums, target, memo);
	}
	int tryCombinationSum4(vector<int>& nums, int target, vector<int>& memo) {
		if (target < 0)return 0;
		if (target == 0) return 1;
		if (memo[target] != -1)return  memo[target];
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res += tryCombinationSum4(nums, target - nums[i], memo);
		}
		return memo[target] = res;
	}
};