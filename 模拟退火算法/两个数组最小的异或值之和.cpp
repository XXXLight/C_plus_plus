#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int n;
	int fun(vector<int>& a, vector<int>& b) {
		int res = 0;
		for (int i = 0; i < n; i++)res += (a[i] ^ b[i]);
		return res;
	}
	int minimumXORSum(vector<int>& a, vector<int>& b) {
		int res = INT_MAX; double eps = 1e-18, d = 0.999; n = a.size();
		for (double t = 1e6; t > eps; t *= d) {
			int pre = fun(a, b); res = min(res, pre);
			int x = rand() % n, y = rand() % n;
			swap(b[x], b[y]);
			int nxt = fun(a, b); res = min(res, nxt);
			if (nxt < pre)continue;
			else {
				if (exp(-1.0*(nxt - pre) / t)*RAND_MAX > rand())continue;
				else swap(b[x], b[y]);
			}
		}
		return res;
	}
};
