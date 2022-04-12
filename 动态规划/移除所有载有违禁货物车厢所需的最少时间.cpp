#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumTime(string s) {
		int n = s.length();
		vector<int> suf(n + 1);
		for (int i = n - 1; i >= 0; --i)
			suf[i] = s[i] == '0' ? suf[i + 1] : min(suf[i + 1] + 2, n - i);
		int ans = suf[0], pre = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == '1') {
				pre = min(pre + 2, i + 1);
				ans = min(ans, pre + suf[i + 1]);
			}
		return ans;
	}
};

