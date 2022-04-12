#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		vector<int> count(128);
		int i = 0, j = 0, cnt = 0, res = 0;
		while (j < s.size()) {
			if (++count[s[j++]] == 1 && ++cnt > 2) {
				while (--count[s[i++]] != 0);
				cnt--;
			}
			res = max(res, j - i);
		}

		return res;
	}
};