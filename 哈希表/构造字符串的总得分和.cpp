#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int bs = 131;
	int mod = 1e9 + 7;
	int n, hs[100007], pw[100007];
	int geths(int l, int r) {
		return ((hs[l] - 1ll * hs[r + 1] * pw[r - l + 1]) % mod + mod) % mod;
	}
	long long sumScores(string s) {
		n = s.length();
		pw[0] = 1;
		for (int i = 1; i <= n; ++i) pw[i] = 1ll * pw[i - 1] * bs % mod;
		for (int i = n; i > 0; --i)
			hs[i] = (1ll * hs[i + 1] * bs + s[i - 1] - 'a') % mod;
		long long ans = 0;
		for (int i = n; i; --i) {
			int len = n - i + 1;
			int l = 0, r = len;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (geths(1, mid) == geths(i, i + mid - 1)) l = mid;
				else r = mid - 1;
			}
			ans += l;
		}
		return ans;
	}
};