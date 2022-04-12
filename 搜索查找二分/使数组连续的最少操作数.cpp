#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minOperations(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		nums.erase(unique(nums.begin(), nums.end()), nums.end());  //去重的库函数

		int setLen = nums.size();
		int result = len;
		int r = 0;
		for (int l = 0; l < setLen; l++) {
			// 二分找到比 nums[l] + len - 1 的值大的第一个位置
			int temp = upper_bound(nums.begin(), nums.begin() + setLen - 1, nums[l] + len - 1) - nums.begin();
			//找到末尾仍然没有找到的时候，判断一下nums的最后一个元素和nums[l] + len - 1的值的大小
			if (nums[setLen - 1] <= nums[l] + len - 1) {
				temp++;
			}
			//while (r < setLen && nums[r] <= nums[l] + len - 1) {
				//r++;
			//}
			result = min(result, len - temp + l);
		}
		return result;
	}
};

