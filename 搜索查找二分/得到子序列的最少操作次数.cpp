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




//������һ������Ԫ�ظ�����ͬʱ����������������⣨LCS������ת��Ϊ��������������⣨LIS��������⡣
//ͬʱ��������������⣨LIS������ʹ�á�ά���������� + ���֡���̰�Ľⷨ�����Ӷ�Ϊ O(n\log{ n })O(nlogn)��
class Solution {
public:
	// �������������еĽӿ�
	class SolutionLIS {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int len = nums.size();
			vector<int> res;
			res.push_back(nums[0]);
			for (int i = 1; i < len; i++) {
				if (nums[i] > res.back()) {// ȷ���������������
					res.push_back(nums[i]);
				}
				else {
					// ��>=nums[i]��index
					int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();// ע����������ȥres.begin()
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