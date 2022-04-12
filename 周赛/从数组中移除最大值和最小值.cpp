#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumDeletions(vector<int>& nums) {
		int Mmax = *max_element(nums.begin(), nums.end());
		int Mmin = *min_element(nums.begin(), nums.end());
		int index1, index2;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == Mmax) index1 = i;
			if (nums[i] == Mmin) index2 = i;
		}
		int res = INT_MAX;
		int a = max(index1, index2) + 1;
		int b = nums.size() - min(index1, index2);
		int c = min(index1, index2) + 1 + nums.size() - max(index1, index2);
		res = min(a, min(b, c));
		return res;
	}
};