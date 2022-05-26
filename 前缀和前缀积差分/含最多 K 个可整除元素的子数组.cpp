#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
	set<vector<int>> mp;
	int countDistinct(vector<int>& nums, int k, int p) {
		int n = nums.size();
		vector<int> preSum;
		preSum.push_back(0);
		int sum = 0;
		for (auto& e : nums) {
			if (e%p == 0) sum++;
			preSum.push_back(sum);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int cnt = preSum[j + 1] - preSum[i];
				if (cnt > k) continue;
				mp.insert(vector<int>(nums.begin() + i, nums.begin() + j + 1));
			}
		}
		return mp.size();
	}
};