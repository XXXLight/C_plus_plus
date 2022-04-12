#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		int maxV = pow(2, maximumBit); // 2^maximumBit�����Ǽ���ָ����,�������
		int x = 0;
		for (auto e : nums) x ^= e;
		int m = -1;
		int index;
		for (int i = 0; i < maxV; i++) {
			if ((x^i) > m) { // λ�������ע�����ȼ���һ��Ҫ�����ţ�����λ��������ž�������
				m = x ^ i;
				index = i;
			}
		}
		vector<int> res;
		res.push_back(index);
		reverse(nums.begin(), nums.end());
		for (auto e : nums) {
			index ^= e;
			res.push_back(index);
		}
		res.pop_back();
		return res;
	}
};