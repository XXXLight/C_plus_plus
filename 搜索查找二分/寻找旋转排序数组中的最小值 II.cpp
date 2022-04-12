#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] < nums[r]) {
				r = m;
			}
			else if (nums[m] > nums[r]) {
				l = m + 1;
			}
			else if (nums[m] == nums[r]) {
				r--;
			}
		}
		return nums[l];
	}
};