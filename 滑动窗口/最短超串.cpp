#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
public:
	unordered_map<int, int> need, window;
	vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
		vector<int> res(2, 0);
		int len = big.size();
		for (auto e : small) need[e]++;
		int p1 = 0, p2 = 0;
		int match = 0;
		int start = 0, minLen = INT_MAX;
		while (p2 < len) {
			int a = big[p2];
			window[a]++;	// 不可直接window[big[p2]]++;
			p2++;
			if (need.count(a) && need[a] == window[a]) match++;
			while (match == need.size()) {
				if (p2 - p1 < minLen) {
					minLen = p2 - p1;
					start = p1;
					res[0] = p1;
					res[1] = p2 - 1;
				}
				int b = big[p1];
				window[b]--;
				p1++;
				if (need.count(b) && need[b] > window[b]) match--;
			}
		}
		if (minLen == INT_MAX) return {};
		return res;
	}
};