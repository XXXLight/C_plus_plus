#include<bits/stdc++.h>
using namespace std;

// 时间复杂度：o(n^2),双指针复杂度是o(n)注意
// 空间复杂度：o(n)，取决于排序的空间复杂度
// 三数之和：for + 双指针； 四数之和： 两层for + 双指针
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return {};
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		set<vector<int>> st; //去重用
		int len = nums.size();
		for (int i = 0; i < len - 1; i++) {
			if (i > 0 && nums[i] == nums[i - 1])  continue; //nums[i] == nums[i + 1]怎么用？
			int p1 = i + 1;
			int p2 = len - 1;
			while (p1 < p2) {
				int sum = nums[i] + nums[p1] + nums[p2];
				if (sum < 0) p1++;
				else if (sum > 0) p2--;
				else if (sum == 0) {
					res.push_back({ nums[i] , nums[p1] , nums[p2] });
					p1++;
					p2--;
				}
			}

		}
		for (auto e : res) {
			st.insert(e);
		}
		res.clear();
		for (auto e : st) res.push_back(e);
		return res;
	}
};