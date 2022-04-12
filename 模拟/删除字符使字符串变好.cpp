#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string makeFancyString(string s) {
		int p = 0;
		int len = s.size();
		string res;
		while (p < len) {
			char cur = s[p];
			int cnt = 0;
			if (s[p] != s[p + 1]) {
				res += s[p];
				p++;
			}
			else {
				while (s[p] == s[p + 1]) {
					p++;
					cnt++;
				}
				if (cnt >= 2) { res += s[p]; res += s[p]; }
				else {
					cnt++;
					while (cnt--) res += s[p];
				}
				p++;
			}

		}
		return res;
	}
};