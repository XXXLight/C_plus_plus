#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		auto newNums = nums;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			int index = (i + k) % len;
			newNums[index] = nums[i];
		}
		nums = newNums;
	}
};

class Solution {
public:
	void rotatePart(vector<int>&v, int l, int r) {
		for (int i = l, j = r; i < j; i++, j--) swap(v[i], v[j]);
	}
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		rotatePart(nums, 0, nums.size() - 1);
		rotatePart(nums, 0, k - 1);
		rotatePart(nums, k, nums.size() - 1);
	}
};