#include<bits/stdc++.h>
using namespace std;

// 单调栈：弹、存、压(pop  res  push)
// Q1：单调增还是单调减？（维护单调递减的栈，递减指的从栈底到栈顶）
// Q2：遍历顺序？（倒序）
class Solution {
public:
	vector<int> MonotonousStack(vector<int> &nums) {
		vector<int> res(nums.size());
		stack<int> st;
		int len = nums.size();
		// 倒着放进去
		for (int i = len - 1; i >= 0; i--) {
			// 弹，弹之前确保非空
			while (!st.empty() && st.top() < nums[i]) {
				st.pop();
			}
			// 倒着存储结果
			res[i] = st.empty() ? -1 : st.top();
			// 压
			st.push(nums[i]);
		}
		return res;
	}
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		map<int, int> mp;
		vector<int> temp = MonotonousStack(nums2);
		for (int i = 0; i < temp.size(); i++) {
			// 输入---》输出的映射
			mp.insert(make_pair(nums2[i], temp[i]));
		}
		for (int i = 0; i < nums1.size(); i++) {
			// 根据输入查询输出
			res.push_back(mp[nums1[i]]);
		}
		return res;
	}
};