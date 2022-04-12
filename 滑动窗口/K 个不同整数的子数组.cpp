#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> num1(n + 1), num2(n + 1);
		int tot1 = 0, tot2 = 0;
		int left1 = 0, left2 = 0, right = 0;
		int ret = 0;
		while (right < n) {
			if (!num1[nums[right]]) {
				tot1++;
			}
			num1[nums[right]]++;
			if (!num2[nums[right]]) {
				tot2++;
			}
			num2[nums[right]]++;
			while (tot1 > k) {
				num1[nums[left1]]--;
				if (!num1[nums[left1]]) {
					tot1--;
				}
				left1++;
			}
			while (tot2 > k - 1) {
				num2[nums[left2]]--;
				if (!num2[nums[left2]]) {
					tot2--;
				}
				left2++;
			}
			ret += left2 - left1;
			right++;
		}
		return ret;
	}
};

