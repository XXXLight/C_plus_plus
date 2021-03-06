#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minKBitFlips(vector<int>& nums, int k) {
		int n = nums.size();
		int ans = 0, revCnt = 0;
		for (int i = 0; i < n; ++i) {
			if (i >= k && nums[i - k] > 1) {
				revCnt ^= 1;
				nums[i - k] -= 2; // 复原数组元素，若允许修改数组 nums，则可以省略
			}
			if (nums[i] == revCnt) {
				if (i + k > n) {
					return -1;
				}
				++ans;
				revCnt ^= 1;
				nums[i] += 2;
			}
		}
		return ans;
	}
};
