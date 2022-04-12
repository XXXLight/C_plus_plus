#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<int, int> mp;
	int findMaxLength(vector<int>& nums) {
		// diff=0��λ����-1���൱�������-1����
		mp[0] = -1;
		// ������
		int cnt0 = 0, cnt1 = 0;
		int res = 0; // ���
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) cnt0++;
			else cnt1++;
			int diff = (cnt0 - cnt1);
			if (mp.count(diff)) {
				res = max(i - mp[diff], res);
			}
			// ȷ���ǵ�һ�γ���ʱ������
			if (not mp.count(diff))
				mp[diff] = i;
		}
		return res;
	}
};