#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int res = 0;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				int high = nums[i] + nums[j];
				int index = lower_bound(nums.begin() + j + 1, nums.end(), high) - nums.begin();
				res += index - j - 1;
			}
		}
		return res;
	}
};