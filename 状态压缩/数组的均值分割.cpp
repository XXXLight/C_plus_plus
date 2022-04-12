#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<double> make(vector<double> nums) { // 枚举子序列的和
		int n = nums.size();
		vector<double> ans(1 << n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (1 << i); ++j) {
				ans[j + (1 << i)] = ans[j] + nums[i];
			}
		}
		return ans;
	}
	bool splitArraySameAverage(vector<int>& nums) {
		int n = nums.size(), sum = 0;
		if (n == 1) return false; // 被坑了一下
		for (int& ev : nums) sum += ev;
		vector<double> dnums(n);
		for (int i = 0; i < n; ++i) {
			dnums[i] = nums[i] - (double)sum / n;
		}
		// 获取所有子序列的和
		vector<double> left = make({ dnums.begin(), dnums.begin() + n / 2 });
		vector<double> right = make({ dnums.begin() + n / 2, dnums.end() });
		// 先判断是否能独自构成答案，注意不能从0开始枚举，0表示不贡献任何元素
		for (int i = 1; i < left.size(); ++i) {
			if (fabs(left[i]) < 1e-5) return true;
		}
		left.erase(left.begin()); left.pop_back(); // 删除全贡献和全不贡献的情况
		for (int i = 1; i < right.size(); ++i) {
			if (fabs(right[i]) < 1e-5) return true;
		}
		right.erase(right.begin()); right.pop_back();
		sort(left.rbegin(), left.rend());
		sort(right.begin(), right.end());
		int l = 0, r = 0; // 双指针
		while (l < left.size() && r < right.size()) {
			double ev = left[l] + right[r];
			if (fabs(ev) < 1e-5) return true;
			else if (ev > 0) l++;
			else r++;
		}
		return false;
	}
};

