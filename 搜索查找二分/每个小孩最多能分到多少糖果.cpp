#include<bits/stdc++.h>
using namespace std;

// 和“完成路途的最少时间”是一样的题目，只不过反过来了

class Solution {
public:
	int maximumCandies(vector<int>& candies, long long k) {
		// 判断每个小孩分到 i 个糖果时是否可以满足要求
		auto check = [&](int i) -> bool {
			long long res = 0;
			for (int c : candies) {
				res += c / i;
			}
			return res >= k;
		};

		// 二分查找
		int l = 1;
		int r = 1 + *max_element(candies.begin(), candies.end());
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (check(mid)) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		return l - 1;
	}
};





class Solution {
public:
	int maximumCandies(vector<int>& candies, long long k) {
		// 判断每个小孩分到 i 个糖果时是否可以满足要求,在函数里面定义函数，把函数当成变量一样
		auto check = [&](int i) -> bool {
			long long res = 0;
			for (int c : candies) {
				res += c / i;
			}
			return res >= k;
		};

		// 二分查找
		int l = 1;
		int r = 1 + *max_element(candies.begin(), candies.end());
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(mid)) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return l - 1;
	}
};

