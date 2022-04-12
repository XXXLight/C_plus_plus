#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		int n = fruits.size();

		// 前缀和，用于求区间 [l, r] 共有多少水果
		vector<int> sum;
		sum.push_back(0);
		for (int i = 1; i <= n; ++i)
			sum.push_back(fruits[i - 1][1] + sum[i - 1]);

		vector<int> pos;
		for (int i = 0; i < n; ++i)
			pos.push_back(fruits[i][0]);

		// 枚举可能抵达的区间
		int ans = 0;
		for (int x = k; x >= 0; --x)
		{
			int y = (k - x) / 2;
			int l, r;
			// x + 2y = k
			l = startPos - x, r = startPos + y;
			auto pl = lower_bound(pos.begin(), pos.end(), l) - pos.begin(), pr = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
			ans = max(ans, sum[pr] - sum[pl]);
			// 2y + x = k
			l = startPos - y, r = startPos + x;
			pl = lower_bound(pos.begin(), pos.end(), l) - pos.begin(), pr = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
			ans = max(ans, sum[pr] - sum[pl]);
		}

		return ans;
	}
};

