#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto left = lower_bound(nums.begin(), nums.end(), target);
		auto right = upper_bound(nums.begin(), nums.end(), target);
		if (left == right)  return vector<int>{-1, -1};
		else  return vector<int>{(int)(left - nums.begin()), (int)(right - nums.begin() - 1)};
	}
};