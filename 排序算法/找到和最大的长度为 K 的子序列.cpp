#include<bits/stdc++.h>
using namespace std;


// 1.理解：这里 两个属性绑定在一起
// 2.当多个属性绑定在一起的时候可以用结构体的方式来解决


// 二维vector方法
class Solution {
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<int> res;
		vector<vector<int>> help(nums.size(), vector<int>(2, 0));
		for (int i = 0; i < nums.size(); i++) {
			help[i][0] = nums[i];
			help[i][1] = i;
		}
		sort(help.begin(), help.end(), [](auto a, auto b) {
			return a[0] > b[0];
		});
		vector<int> index;
		for (int i = 0; i < k; i++) {
			index.push_back(help[i][1]);
		}
		sort(index.begin(), index.end());
		for (auto e : index) res.push_back(nums[e]);
		return res;
	}
};



// 写成vector<pair<int, int>> vals;   // 辅助数组
class Solution {
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		int n = nums.size();
		vector<pair<int, int>> vals;   // 辅助数组
		for (int i = 0; i < n; ++i) {
			vals.emplace_back(i, nums[i]);
		}
		// 按照数值降序排序
		sort(vals.begin(), vals.end(), [&](auto x1, auto x2) {
			return x1.second > x2.second;
		});
		// 取前 k 个并按照下标升序排序
		sort(vals.begin(), vals.begin() + k);
		vector<int> res;   // 目标子序列
		for (int i = 0; i < k; ++i) {
			res.push_back(vals[i].second);
		}
		return res;
	}
};

