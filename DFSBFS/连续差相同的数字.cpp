#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> numsSameConsecDiff(int n, int k) {
		vector<int> ans;
		if (n == 1)
			ans.push_back(0);
		for (int i = 1; i < 10; i++)
			dfs(i, 1, n, k, ans);
		return ans;
	}

	void dfs(int num, int index, int n, int k, vector<int>& ans) {
		if (index == n) {
			ans.push_back(num);
			return;
		}
		int tmp = num % 10;
		if (tmp + k < 10)
			dfs(num * 10 + tmp + k, index + 1, n, k, ans);
		if (k && tmp - k >= 0)
			dfs(num * 10 + tmp - k, index + 1, n, k, ans);
	}
};

