#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> maxScoreIndices(vector<int>& nums) {
		vector<int> pre0, pre1, v, res(nums.size() + 1, 0);
		pre0.push_back(0), pre1.push_back(0);
		int count0 = 0, count1 = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) count0++;
			pre0.push_back(count0);
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] == 1) count1++;
			pre1.push_back(count1);
		}
		for (int i = 0; i <= nums.size(); i++) {
			res[i] = pre0[i] + pre1[nums.size() - i];
		}
		int m = *max_element(res.begin(), res.end());
		for (int i = 0; i <= nums.size(); i++) {
			res[i] = pre0[i] + pre1[nums.size() - i];
			if (res[i] == m) v.push_back(i);
		}
		return v;
	}
};