#include<bits/stdc++.h>
using namespace std;

// ����ջ�������桢ѹ(pop  res  push)
// Q1�����������ǵ���������ά�������ݼ���ջ���ݼ�ָ�Ĵ�ջ�׵�ջ����
// Q2������˳�򣿣�����
class Solution {
public:
	vector<int> MonotonousStack(vector<int> &nums) {
		vector<int> res(nums.size());
		stack<int> st;
		int len = nums.size();
		// ���ŷŽ�ȥ
		for (int i = len - 1; i >= 0; i--) {
			// ������֮ǰȷ���ǿ�
			while (!st.empty() && st.top() < nums[i]) {
				st.pop();
			}
			// ���Ŵ洢���
			res[i] = st.empty() ? -1 : st.top();
			// ѹ
			st.push(nums[i]);
		}
		return res;
	}
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		map<int, int> mp;
		vector<int> temp = MonotonousStack(nums2);
		for (int i = 0; i < temp.size(); i++) {
			// ����---�������ӳ��
			mp.insert(make_pair(nums2[i], temp[i]));
		}
		for (int i = 0; i < nums1.size(); i++) {
			// ���������ѯ���
			res.push_back(mp[nums1[i]]);
		}
		return res;
	}
};