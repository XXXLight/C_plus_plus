#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0) return myPow(1 / x, abs(n));
		long long N = n;
		if (N == 0) return 1.0;
		double ans = 1;
		while (N) {
			if (N & 1) {
				ans *= x;
			}
			x *= x;
			N = N >> 1; // 出现N>>1的低级错误
		}
		return ans;
	}
};

class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0) return myPow(1 / x, abs(n));
		if (n == 0) return 1.0;
		double tmp = myPow(x, n / 2);
		if (n & 1) return x * tmp*tmp;
		else return tmp * tmp;
	}
};