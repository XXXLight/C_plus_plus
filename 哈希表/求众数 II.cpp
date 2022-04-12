#include<bits/stdc++.h>
using namespace std;


// 摩尔投票,核心在于相互抵消
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		if (nums.empty())return {};
		// 两个候选人，两个计数器
		int m = 0, cm = 0;
		int n = 0, cn = 0;
		for (auto num : nums)
			if (m == num)cm++;
			else if (n == num)cn++;
			else if (cm == 0)m = num, cm++;
			else if (cn == 0)n = num, cn++;
			else cm--, cn--;
		cm = cn = 0;
		for (auto num : nums)
			if (num == m)cm++;
			else if (num == n)cn++;
		vector<int>res;
		int size = nums.size();
		if (cm > size / 3)res.push_back(m);
		if (cn > size / 3)res.push_back(n);
		return res;
	}
};

