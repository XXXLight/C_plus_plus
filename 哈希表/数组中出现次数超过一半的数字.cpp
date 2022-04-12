#include<bits/stdc++.h> 
using namespace std;

// sort取中间
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

// 摩尔投票，核心在于相互抵消
// 时间复杂度：o（n），空间复杂度o(1)
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int x = 0, cx = 0;// x代表候选人，cx候选人的票数
		for (int num : nums) {
			if (x == num) cx++;
			else if (cx == 0) x = num, cx++; // 当前数为众数
			else cx--;
		}
		cx = 0;
		// 验证 x 是否为众数
		for (int num : nums)
			if (num == x) cx++;
		return cx > nums.size() / 2 ? x : 0; // 当无众数时返回 0
	}
};
