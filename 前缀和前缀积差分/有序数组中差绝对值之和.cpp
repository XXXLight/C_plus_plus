#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		vector<int> presum(nums.size() + 1);
		vector<int> res(nums.size());
		int j = nums.size() - 1;
		for (int i = 1; i < presum.size(); i++) {
			presum[i] = presum[i - 1] + nums[i - 1];
		}
		for (int i = 0; i < nums.size(); i++) {
			res[i] = (2 * i - j)*nums[i] - presum[i] + presum[j + 1] - presum[i + 1];
		}
		return res;
	}
};

