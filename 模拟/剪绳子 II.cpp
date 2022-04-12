#include<bits/stdc++.h>
using namespace std;

const int eps = 1e9 + 7;
class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3) return n - 1;
		long long res = 1;
		while (n > 4) {
			n -= 3;
			res *= 3;
			res %= eps;
		}
		res *= n;
		res %= eps;
		return res;
	}
};