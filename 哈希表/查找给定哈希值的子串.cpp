#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long v[20010], p[20010];
	string subStrHash(string s, int pow, int mod, int k, int hashValue) {
		reverse(s.begin(), s.end());
		int n = s.size();
		p[0] = 1;
		for (int i = 1; i <= n; i++) {
			p[i] = p[i - 1] * pow % mod;
			v[i] = (v[i - 1] * pow + (s[i - 1] - 'a' + 1)) % mod;

		}
		int t = p[k];
		string res;
		for (int i = k; i <= n; i++) {
			int val = (v[i] - v[i - k] * t) % mod;
			if (val < 0) {
				val = (val + mod) % mod;
			}
			if (val == hashValue) {
				res = s.substr(i - k, k);
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};