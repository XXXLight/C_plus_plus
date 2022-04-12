#include<bits/stdc++.h>
using namespace std;

// 要想到前缀和

class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		vector<int> res(nums.size(), -1);
		vector<long long> preSum;
		preSum.push_back(0);
		long long sum = 0;
		for (auto e : nums) {
			sum += e;
			preSum.push_back(sum);
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i - k >= 0 && i + k < nums.size()) {
				// 前缀和的公式：[i,j]范围内的前缀和是preSum[j+1]-preSum[i]
				res[i] = (preSum[i + k + 1] - preSum[i - k]) / (2 * k + 1);
			}
		}
		return res;
	}
};