#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 时间复杂度：o(n)
// 空间复杂度：o(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		// 走到i的时候，hash表[0,i-1]
		for (int i = 0; i < nums.size(); i++) {
			if (mp.count(target - nums[i])) {
				return { i,mp[target - nums[i]] };
			}
			mp[nums[i]] = i;
		}
		return {};
	}
};