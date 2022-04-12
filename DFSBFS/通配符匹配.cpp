#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string s, p;
	int n, m;
	unordered_map<long, bool> memo;

	bool dfs(int i, int j) {
		if (j == m) return i == n;
		long id = ((long)i << 8) | j;
		if (memo.count(id)) return memo[id];

		if (p[j] == '*') {
			bool ret = false;
			for (int k = i; k <= n; k++) {
				ret = ret || dfs(k, j + 1);
			}
			return memo[id] = ret;
		}
		else {
			bool first = i < n && (s[i] == p[j] || p[j] == '?');
			return memo[id] = first && dfs(i + 1, j + 1);
		}
	}

	bool isMatch(string s, string p) {
		this->s = s;
		this->p = p;
		n = s.length();
		m = p.length();
		return dfs(0, 0);
	}
};