#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int cnt = 0;
		int res = INT_MIN;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] < nums[i + 1]) {
				cnt++;
				res = max(res, cnt);
			}
			else {
				cnt = 0;
			}
		}
		return res == INT_MIN ? 1 : res + 1;
	}
};