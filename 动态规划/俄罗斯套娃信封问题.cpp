#include<bits/stdc++.h>
using namespace std;

// ʱ�临�Ӷȣ�o(n^2),����forѭ��
// �ռ临�Ӷȣ�o(n)��dp����
class Solution {
public:
	// ����������нӿ�
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 1);
		for (int j = 1; j < len; j++) {
			for (int i = 0; i < j; i++) {
				// j�ǳ����ˣ�i�Ǳ�����dp[j]Ҳ�ǳ���
				if (nums[i] < nums[j]) {
					dp[j] = max(dp[j], dp[i] + 1); //����������ֵ
				}
			}
		}
		return *max_element(dp.begin(), dp.end()); //ע�ⷵ�ص���dp�����е����ֵ
	}
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		// ����sort����ֵ��ѧϰ������һά����ͬʱ���ڶ�ά�Ƚ�������
		// �����[0]��[1]�ȴ���ά��
		sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
			return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);	// ���ǰ���һά���򣬶�ά����Ĺ���
		});
		vector<int> v;
		// ȡ���ڶ���ά��
		for (auto e : envelopes) {
			v.push_back(e[1]);
		}
		int res = lengthOfLIS(v);
		return res;
	}
};