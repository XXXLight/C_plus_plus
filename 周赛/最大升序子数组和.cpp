#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxAscendingSum(vector<int>& nums) {
		int ans = 0, sum = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			if (i == 0 || nums[i] > nums[i - 1]) {
				sum += nums[i];
			}
			else {
				sum = nums[i];
			}
			ans = max(ans, sum);
		}
		return ans;
	}
};