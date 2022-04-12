#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		string s;
		for (int len = max(0, k - n); len <= min(k, m); ++len)
			s = max(s, merge(maxSub(nums1, len), maxSub(nums2, k - len)));
		vector<int> ans;
		for (auto c : s) ans.push_back(c - '0');
		return ans;
	}

	string maxSub(vector<int>& nums, int k) {//��Ϊ k �����������
		int n = nums.size(), top = -1, remain = n - k;
		string s(k, '0');//����ջ
		for (int i = 0; i < n; ++i) {
			while (top >= 0 && s[top] - '0' < nums[i] && remain > 0) {
				--top;
				--remain;
			}
			if (top < k - 1) {
				++top;
				s[top] = nums[i] + '0';
			}
			else {
				--remain;
			}
		}
		return s;
	}

	string merge(const string& s, const string& t) {//�ϲ�����������
		string res;
		for (int i = 0, j = 0; i < s.size() || j < t.size(); ) {
			if (s.substr(i) > t.substr(j)) {//̰�ģ������Ż��ռ�
				res.push_back(s[i++]);
			}
			else {
				res.push_back(t[j++]);
			}
		}
		return res;
	}
};
