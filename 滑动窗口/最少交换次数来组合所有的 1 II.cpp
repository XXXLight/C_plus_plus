#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minSwaps(vector<int>& nums) {
		int len = nums.size();
		// ͳ������nums��1�ĸ���
		int cnt1 = 0;
		for (int i = 0; i < len; i++) {
			if (nums[i] == 1) cnt1++;
		}
		// help���鹹�컷�����飬��ԭʼ�������������
		vector<int> help;
		help.resize(2 * len);
		for (int i = 0; i < 2 * len; i++) {
			help[i] = nums[i%len];
		}
		// ������СΪcnt1�Ĵ��ڣ���ⴰ�������1�ĸ���
		int sum = 0;
		for (int i = 0; i < cnt1; i++) {
			sum += nums[i];
		}
		int res = sum;
		for (int i = cnt1; i < 2 * len; i++) {
			sum += help[i] - help[i - cnt1];
			res = max(res, sum);
		}
		return cnt1 - res;
	}
};


// ʱ�临�Ӷȳ�ʱ�İ汾
class Solution {
public:
	int minSwaps(vector<int>& nums) {
		int len = nums.size();
		int cnt1 = 0;
		for (int i = 0; i < len; i++) {
			if (nums[i] == 1) cnt1++;
		}
		vector<int> help;
		help.resize(2 * len);
		for (int i = 0; i < 2 * len; i++) {
			help[i] = nums[i%len];
		}
		int res = INT_MAX;
		for (int i = 0; i + cnt1 < 2 * len; i++) {
			int cnt0 = 0;
			for (int j = i; j < i + cnt1; j++) {
				if (help[j] == 0) cnt0++;
			}
			res = min(cnt0, res);
		}
		return res;
	}
};