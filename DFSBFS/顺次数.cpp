#include<bits/stdc++.h>
using namespace std;

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