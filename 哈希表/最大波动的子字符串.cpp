#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int largestVariance(string &s) {
		int ans = 0;
		for (char a = 'a'; a <= 'z'; ++a)
			for (char b = 'a'; b <= 'z'; ++b) {
				if (a == b) continue;
				int diff = 0, diff_with_b = -s.length();
				for (char ch : s) {
					if (ch == a) {
						++diff;
						++diff_with_b;
					}
					else if (ch == b) {
						diff_with_b = --diff;
						diff = max(diff, 0);
					}
					ans = max(ans, diff_with_b);
				}
			}
		return ans;
	}
};

