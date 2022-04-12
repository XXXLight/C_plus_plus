#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int maxLength = 0;
		unordered_map<int, int> mp;
		int counter = 0;
		mp[counter] = -1;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int num = nums[i];
			if (num == 1) {
				counter++;
			}
			else {
				counter--;
			}
			if (mp.count(counter)) {
				int prevIndex = mp[counter];
				maxLength = max(maxLength, i - prevIndex);
			}
			else {
				mp[counter] = i;
			}
		}
		return maxLength;
	}
};


// ������������������ʵ����ֻ��һ��������
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int len = nums.size();
		unordered_map<int, int> mp;
		int cnt0 = 0, cnt1 = 0;
		int res = 0;
		mp[0] = -1; // ��ʼ��ʱ��cnt0-cnt1=0,��Ӧ���±���-1
		for (int i = 0; i < len; i++) {
			if (nums[i] == 0) cnt0++; else cnt1++;
			if (mp.count(cnt0 - cnt1)) {
				res = max(res, i - mp[cnt0 - cnt1]);
			}
			// ȷ��cnt0-cnt1�ǵ�һ�γ���ʱ������
			if (not mp.count(cnt0 - cnt1)) mp[cnt0 - cnt1] = i;
		}
		return res;
	}
};