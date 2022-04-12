#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		vector<int> count(128);
		int i = 0, j = 0, cnt = 0, res = 0;
		// 这样写的代码说实话挺鸡肋的
		while (j < s.size()) {
			if (++count[s[j++]] == 1 && ++cnt > k) {
				while (--count[s[i++]] != 0);
				cnt--;
			}
			res = max(res, j - i);
		}

		return res;
	}
};


class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		unordered_map<char, int> count;
		int i = 0, j = 0, cnt = 0, res = 0;
		while (j < s.size()) {
			count[s[j]]++;
			if (count[s[j]] == 1) {
				cnt++;
				if (cnt > k) {
					while (--count[s[i++]] != 0);
					cnt--;
				}
			}
			j++;
			res = max(res, j - i);
		}
		return res;
	}
};


class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		unordered_map<char, int> map;
		if (k == 0) { return 0; }
		int n = s.size();
		int ans = 0;
		for (int l = 0, r = 0; r < n; r++) {
			map[s[r]]++;
			while (map.size() > k) {
				map[s[l]]--;
				if (map[s[l]] == 0) { map.erase(s[l]); }
				l++;
			}
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};

