#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	long long sumScores(string s) {
		int n = s.length();
		long ans = n;
		vector<int> z(n);
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			z[i] = max(min(z[i - l], r - i + 1), 0);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
				l = i;
				r = i + z[i];
				++z[i];
			}
			ans += z[i];
		}
		return ans;
	}
};

