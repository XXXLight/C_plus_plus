#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumMountainRemovals(vector<int>& nums) {
		vector<int> LISs(nums.size()), reverseLISs(nums.size());

		getLISs(nums, LISs);
		reverse(nums.begin(), nums.end());
		getLISs(nums, reverseLISs);

		return getMinRemovals(LISs, reverseLISs);
	}

	void getLISs(vector<int>& nums, vector<int>& LISs) {
		int i, size = nums.size(), len = 1;
		vector<int> incNums = { nums[0] };
		LISs[0] = 1;

		for (i = 1; i < size; ++i) {
			if (nums[i] > incNums[len - 1]) {
				incNums.push_back(nums[i]);
				LISs[i] = ++len;
			}
			else {
				auto iter = upper_bound(incNums.begin(), incNums.end(), nums[i] - 1);
				*iter = nums[i];
				LISs[i] = distance(incNums.begin(), iter) + 1;
			}
		}
	}

	int getMinRemovals(vector<int>& LISs, vector<int>& reverseLISs) {
		int i, size = LISs.size(), maxMountain = 0;

		for (i = 0; i < size; ++i) {
			if (LISs[i] > 1 && reverseLISs[size - 1 - i] > 1) {  // 必须要能够形成一个山，所以LIS最少长度需要2
				maxMountain = max(maxMountain, LISs[i] + reverseLISs[size - 1 - i]);
			}
		}

		return size - maxMountain + 1;
	}
};
