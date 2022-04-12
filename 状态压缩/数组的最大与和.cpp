#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maximumANDSum(vector<int>& nums, int s) {
		int n = nums.size(), M = 1;
		for (int i = 0; i < s; ++i) M *= 3;
		int f[n + 1][M];
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < M; ++j) {
				int t = j, w = 1;
				for (int k = 1; k <= s; ++k) {
					if (t % 3) {
						f[i][j] = max(f[i][j], f[i - 1][j - w] + (k & nums[i - 1]));
					}
					t /= 3;
					w *= 3;
				}
			}
		}

		return f[n][M - 1];
	}
};

