#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<int, int> mp;
	int findMaxLength(vector<int>& nums) {
		// diff=0的位置是-1，相当于数组的-1索引
		mp[0] = -1;
		// 计数器
		int cnt0 = 0, cnt1 = 0;
		int res = 0; // 结果
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) cnt0++;
			else cnt1++;
			int diff = (cnt0 - cnt1);
			if (mp.count(diff)) {
				res = max(i - mp[diff], res);
			}
			// 确保是第一次出现时的索引
			if (not mp.count(diff))
				mp[diff] = i;
		}
		return res;
	}
};