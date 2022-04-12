#include<bits/stdc++.h>
using namespace std;

// 先写暴力算法，再用双指针，暴力o(n^4),双指针o(n^3)
// 暴力四层循环
// 算法优化都是从暴力算法开始
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end()); //排序
		vector<vector<int>> res;
		set<vector<int>> st; //用于去重操作
		int len = nums.size();
		for (int i = 0; i < len; i++) { //后面的都是末尾len
			for (int j = i + 1; j < len; j++) {
				int p1 = j + 1;
				int p2 = len - 1;
				while (p1 < p2) {
					int sum = nums[i] + nums[j] + nums[p1] + nums[p2];
					if (sum == target) {
						res.push_back({ nums[i] , nums[j] , nums[p1] , nums[p2] });
						p1++;
						p2--;
					}
					else if (sum < target) {
						p1++;
					}
					else if (sum > target) {
						p2--;
					}
				}
			}
		}
		for (auto e : res) {
			st.insert(e);
		}
		res.clear();
		for (auto e : st) {
			res.push_back(e);
		}
		return res;
	}
};