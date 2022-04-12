#include<bits/stdc++.h>
using namespace std;

// 枚举2^16可以接收
class Solution {
public:
	int ans = 0;
	int countMaxOrSubsets(vector<int>& nums) {
		// 按位或是不减的操作，所以全部 | 起来是最大值
		int sum = 0;
		for (auto p : nums) {
			sum |= p;
		}
		vector<vector<int>> res = subsets(nums);
		for (auto e : res) {
			int tmp = 0;
			for (auto e1 : e) {
				tmp |= e1;
			}
			if (tmp == sum) ans++;
		}
		return ans;
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int len = pow(2, nums.size());//int len = 2 << (nums.size() - 1);
		vector<int> r;
		for (int mask = 0; mask < len; mask++) {
			for (int j = 0; j < nums.size(); j++) {
				if ((1 << j)&mask)   // if ((i >> j) & 1)
					r.push_back(nums[j]);
			}
			res.push_back(r);
			r.clear();
		}
		return res;
	}
};




class Solution {
public:
	int ans = 0;
	int countMaxOrSubsets(vector<int>& nums) {
		// 按位或是不减的操作，所以全部 | 起来是最大值
		int sum = 0;
		for (auto p : nums) {
			sum |= p;
		}
		dfs(nums, sum, 0, 0);
		return ans;
	}
	void dfs(vector<int>& nums, int& m, int idx, int cur) {
		// 剪枝
		if (cur == m) {
			ans += 1 << (nums.size() - idx);
			return;
		}
		if (idx == nums.size()) {
			return;
		}
		// 加上这个数
		dfs(nums, m, idx + 1, cur | nums[idx]);
		// 不加这个数
		dfs(nums, m, idx + 1, cur);
	}
};

