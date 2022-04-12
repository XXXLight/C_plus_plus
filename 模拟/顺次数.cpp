#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> r = {
			12, 23, 34, 45, 56, 67, 78, 89,
			123, 234, 345, 456, 567, 678, 789,
			1234, 2345, 3456,4567, 5678, 6789,
			12345, 23456, 34567, 45678, 56789,
			123456, 234567, 345678, 456789,
			1234567, 2345678, 3456789,
			12345678, 23456789,
			123456789
		};
		vector<int> res;
		for (auto e : r) {
			if (e >= low && e <= high)
				res.push_back(e);
		}
		return res;
	}
};


class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> res;
		for (int i = 1; i <= 9; i++) {
			dfs(res, i, i, low, high);
		}
		sort(res.begin(), res.end());
		return res;
	}
private:
	void dfs(vector<int>& res, long cur, int last, int low, int high) {
		if (cur > high) {
			return;
		}
		if (cur >= low) {
			res.push_back(cur);
		}
		if (last == 9) return;
		dfs(res, cur * 10 + last + 1, last + 1, low, high);
	}
};