#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minOperations(vector<int> &target, vector<int> &arr) {
		int n = target.size();
		unordered_map<int, int> pos;
		for (int i = 0; i < n; ++i) {
			pos[target[i]] = i;
		}
		vector<int> d;
		for (int val : arr) {
			if (pos.count(val)) {
				int idx = pos[val];
				auto it = lower_bound(d.begin(), d.end(), idx);
				if (it != d.end()) {
					*it = idx;
				}
				else {
					d.push_back(idx);
				}
			}
		}
		return n - d.size();
	}
};




//当其中一个数组元素各不相同时，最长公共子序列问题（LCS）可以转换为最长上升子序列问题（LIS）进行求解。
//同时最长上升子序列问题（LIS）存在使用「维护单调序列 + 二分」的贪心解法，复杂度为 O(n\log{ n })O(nlogn)。
class Solution {
public:
	// 求解最长上升子序列的接口
	class SolutionLIS {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int len = nums.size();
			vector<int> res;
			res.push_back(nums[0]);
			for (int i = 1; i < len; i++) {
				if (nums[i] > res.back()) {// 确保是最长上升子序列
					res.push_back(nums[i]);
				}
				else {
					// 找>=nums[i]的index
					int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();// 注意这里必须减去res.begin()
					res[index] = nums[i];
				}
			}
			return res.size();
		}
	};
	int minOperations(vector<int>& target, vector<int>& arr) {
		unordered_map<int, int> mp;
		for (int i = 0; i < target.size(); i++) {
			mp[target[i]] = i;
		}
		vector<int> v;
		for (int i = 0; i < arr.size(); i++) {
			if (mp.count(arr[i])) {
				v.push_back(mp[arr[i]]);
			}
		}
		if (v.size() == 0) return target.size();
		return target.size() - SolutionLIS().lengthOfLIS(v);
	}
};