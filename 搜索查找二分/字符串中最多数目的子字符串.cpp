#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> index1, index2;
	long long maximumSubsequenceCount(string t, string p) {
		char p1 = p[0], p2 = p[1];
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == p1) index1.push_back(i);
			else if (t[i] == p2)index2.push_back(i);
		}
		if (p1 == p2) return (index1.size() + 1)*index1.size() / 2;
		long long res = 0;
		for (int i = 0; i < index1.size(); i++) {
			int in = lower_bound(index2.begin(), index2.end(), index1[i]) - index2.begin();
			res += (index2.size() - in);
		}
		res += max(index1.size(), index2.size());
		return res;
	}
};