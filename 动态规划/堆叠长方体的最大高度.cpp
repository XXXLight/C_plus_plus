#include<bits/stdc++.h>
using namespace std;

//理解：属于三维套娃问题
// 时间复杂度：o(n^2)
// 空间复杂度：o(n)
// 难点：sort
class Solution {
public:
	int maxHeight(vector<vector<int>>& cuboids) {
		int n = cuboids.size();
		for (auto& cubic : cuboids) {
			sort(cubic.begin(), cubic.end());
		}
		sort(cuboids.begin(), cuboids.end(), [](const auto& u, const auto& v) {
			return pair(u[2], u[0] * u[1]) < pair(v[2], v[0] * v[1]); //改为u[0] + u[1]也是可以的
		});
		vector<int> f(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
					f[i] = max(f[i], f[j]);
				}
			}
			f[i] += cuboids[i][2];
		}

		return *max_element(f.begin(), f.end());
	}
};


class Solution {
public:
	int maxHeight(vector<vector<int>>& cuboids) {
		int n = cuboids.size();
		for (auto &c : cuboids)
			sort(c.begin(), c.end());
		sort(cuboids.begin(), cuboids.end());
		vector<int> dp(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			dp[i] = cuboids[i][2];
			// j<=i 会导致重复计算
			for (int j = 0; j < i; ++j)
				if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
					dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

