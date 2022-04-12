#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long f(long long n) {
		long long result = 0ll;
		for (long long p = n / 5; p; p /= 5)
			result += p;
		return result;
	}

	int preimageSizeFZF(int K) {
		long long r = 1ll + 5ll * K;
		long long l = 4ll * K;
		while (l < r) {
			long long m = (l + r) / 2;
			if (f(m) < K) l = m + 1;
			else r = m;
		}
		return f(l) == K ? 5 : 0;
	}
};

