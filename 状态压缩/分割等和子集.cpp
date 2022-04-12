#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1) return false;
		bitset<10001> dp(1);
		for (int n : nums) dp |= dp << n;
		return dp[sum >> 1];
	}
};


class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		return !(sum & 1) &&
			accumulate(nums.begin(), nums.end(), bitset<10001>(1),
				[](const bitset<10001> &dp, int n) { return dp | dp << n; })[sum >> 1];
	}
};