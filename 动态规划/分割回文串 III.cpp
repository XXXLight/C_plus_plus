#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int cost(string& s, int l, int r) {
		int ret = 0;
		for (int i = l, j = r; i < j; ++i, --j) {
			if (s[i] != s[j]) {
				++ret;
			}
		}
		return ret;
	}

	int palindromePartition(string& s, int k) {
		int n = s.size();
		vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
		f[0][0] = 0;
		// 注意i从1~n，是包含的
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= min(k, i); ++j) {
				// 分成1段，直接将[0,i-1]也就是原始字符串修改成回文就可以了
				if (j == 1) {
					f[i][j] = cost(s, 0, i - 1);
				}
				else {
					for (int i0 = j - 1; i0 < i; ++i0) {
						// 前i个分成j段；前i0个分成j-1段，[i0,i-1]之间的字符串修改成回文串所需要的次数
						f[i][j] = min(f[i][j], f[i0][j - 1] + cost(s, i0, i - 1));
					}
				}
			}
		}

		return f[n][k];
	}
};

