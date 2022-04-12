#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumDifference(vector<int>& nums) {
		int n = nums.size() / 2;
		/*
		首先，预处理前n个元素，有2的n次方种状态（即每个元素选或不选），用二进制位的1代表选，0代表不选。
		换句话说，用1代表元素归入第一个数组，用0代表归入第二个数组。
		这里用sum_pre表示前n个数，归为第一个数组的，和归为第二个数组的元素之差。
		*/
		vector<int>pre[16];  //pre[i]表示选取i个元素时，和的集合
		for (int i = 0; i < (1 << n); i++) {
			int sum_pre = 0, bit = 0;
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					sum_pre += nums[j];
					bit++;
				}
				else {
					sum_pre -= nums[j];
				}
			}
			pre[bit].push_back(sum_pre);
		}
		//排序，为了后面二分查找。顺便去重，也可以不去重
		for (int i = 0; i <= n; i++) {
			sort(pre[i].begin(), pre[i].end());
			pre[i].erase(unique(pre[i].begin(), pre[i].end()), pre[i].end());
		}

		/*
		考虑后n个数。若后n个数选出bit个归入第一个数组，那么只需从前n个数中拿n-bit个归入第一个数组。
		选数的方式与上面相同，枚举2的n次方个状态。
		对于每个状态，利用二分查找从上面的数组pre[n-bit]中找到一个数k，使得k加上当前的sum_later尽量接近0
		记录下最小的差值即可。
		*/
		int ans = 1e9 + 7;
		for (int i = 0; i < (1 << n); i++) {
			int sum_later = 0, bit = 0;
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					sum_later += nums[j + n];
					bit++;
				}
				else {
					sum_later -= nums[j + n];
				}
			}
			auto it = lower_bound(pre[n - bit].begin(), pre[n - bit].end(), -sum_later);
			if (it != pre[n - bit].end())
				ans = min(ans, sum_later + *it);
		}
		return ans;
	}
};

