#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 纯暴力的方法，会超时
class Solution {
public:
	int countTriplets(vector<int> A) {
		int sum = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A.size(); j++)
			{
				for (int k = 0; k < A.size(); k++)
					if ((A[i] & A[j] & A[k]) == 0)
					{
						sum++;
					}
			}
		}
		return sum;
	}
};


// 空间换时间，先算出两层for循环的，存到哈希表里，然后再用之前的结果
class Solution {
public:
	int countTriplets(vector<int>& nums) {
		unordered_map<int, int>num2cnt;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num2cnt[nums[i] & nums[j]]++;
			}
		}
		int ans = 0;
		for (auto&[num, cnt] : num2cnt) {
			for (int i = 0; i < n; i++) {
				if ((nums[i] & num) == 0)ans += cnt;
			}
		}
		return ans;
	}
};

