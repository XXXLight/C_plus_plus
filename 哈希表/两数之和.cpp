#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 时间复杂度：o(n)
// 空间复杂度：o(n),主要是开哈希表
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.count(target - nums[i])) {
				return { mp[target - nums[i]], i };
			}
			mp[nums[i]] = i; //这条语句必须放在后面
		}
		return {};
	}
};