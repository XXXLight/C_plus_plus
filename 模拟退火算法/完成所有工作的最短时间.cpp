#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

	static constexpr int N = 15;

	int kk, n;
	int w[N], s[N];
	int ans = 2e9;

	int calc() {
		for (int i = 0; i < kk; i++) s[i] = 0;
		for (int i = 0; i < n; i++) {
			int k = 0;
			for (int j = 1; j < kk; j++) {
				if (s[j] < s[k]) k = j;
			}
			s[k] += w[i];
		}
		int res = 0;
		for (int i = 0; i < kk; i++) res = max(res, s[i]);
		ans = min(ans, res);
		return res;
	}

	void simulate_anneal() {
		random_shuffle(w, w + n);
		for (double t = 1e4; t > 1e-4; t *= 0.95) {
			int a = rand() % n, b = rand() % n;
			int resa = calc();
			swap(w[a], w[b]);
			int resb = calc();
			int dt = resb - resa;
			if (exp(-dt / t) > rand() / RAND_MAX) continue;
			swap(w[a], w[b]);
		}
	}

	int minimumTimeRequired(vector<int>& jobs, int k) {
		n = jobs.size();
		kk = k;
		for (int i = 0; i < n; i++) w[i] = jobs[i];
		for (int i = 0; i < 100; i++) {
			simulate_anneal();
		}
		return ans;
	}
};


