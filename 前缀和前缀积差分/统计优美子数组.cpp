#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> sum(nums.size() + 1); //sum用来统计截止当前位置奇数出现的累计个数，其实就是另外一种前缀和
		sum[0] = 0;
		int cnt = 0;//计数器
		int res = 0;//结果
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] & 1) cnt++;//是奇数则计数器加一
			sum[i + 1] = cnt;
		}
		//对“前缀和数组”进行遍历
		for (int i = 0; i < sum.size(); i++) {
			mp[sum[i]]++;
			if (sum[i] >= k) {//可以不作判断直接找，但是这样效率会更高
				res += mp[sum[i] - k];
			}
		}
		return res;
	}
};