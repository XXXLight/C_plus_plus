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


// 用了两个计数器，其实可以只用一个计数器
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int len = nums.size();
		unordered_map<int, int> mp;
		int cnt0 = 0, cnt1 = 0;
		int res = 0;
		mp[0] = -1; // 初始化时：cnt0-cnt1=0,对应的下标是-1
		for (int i = 0; i < len; i++) {
			if (nums[i] == 0) cnt0++; else cnt1++;
			if (mp.count(cnt0 - cnt1)) {
				res = max(res, i - mp[cnt0 - cnt1]);
			}
			// 确保cnt0-cnt1是第一次出现时的索引
			if (not mp.count(cnt0 - cnt1)) mp[cnt0 - cnt1] = i;
		}
		return res;
	}
};