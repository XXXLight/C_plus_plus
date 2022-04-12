#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> s;
	int sz;
	int ret;
	int calc() {
		int c = s[0];
		for (int i = 1; i < s.size(); ++i) {
			c = abs(c - s[i]);
		}
		ret = min(ret, c);
		return c;
	}

	void sa() {
		random_shuffle(s.begin(), s.end());
		for (double t = 1e6; t > 1e-4; t *= 0.95) {
			int a = rand() % sz;
			int b = rand() % sz;
			int res1 = calc();
			swap(s[a], s[b]);
			int res2 = calc();
			double d = res1 - res2;
			if (exp(-d / t) > (rand()*1.0 / RAND_MAX))
				swap(s[a], s[b]);
		}
	}

	int lastStoneWeightII(vector<int>& _s) {
		s = std::move(_s);
		sz = s.size();
		ret = calc();
		for (int i = 0; i <= 80; ++i) sa();
		return ret;
	}
};

