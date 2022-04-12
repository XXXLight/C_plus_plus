#include<bits/stdc++.h>
using namespace std;

// 时间复杂度：o(n^2)
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int res = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < len - 2; i++) {
			int p1 = i + 1;
			int p2 = len - 1;
			while (p1 < p2) {
				int sum = nums[i] + nums[p1] + nums[p2];
				if (abs(sum - target) < abs(res - target)) {
					res = sum;
				}
				// 以下三种情况都有
				if (sum == target) {
					return target;
				}
				else if (sum < target) {
					p1++;
				}
				else if (sum > target) {
					p2--;
				}
			}
		}
		return res;
	}
};