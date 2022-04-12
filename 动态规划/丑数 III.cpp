#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
	inline long gcd(long a, long b) {
		return b > 0 ? gcd(b, a%b) : a;
	}
	long LCM(long a, long b) {
		return a * (b / gcd(a, b));
	}
	int nthUglyNumber(int n, int a, int b, int c) {
		long ab = LCM(a, b);
		long ac = LCM(a, c);
		long bc = LCM(b, c);
		long abc = LCM(ab, c);
		long l = min(a, min(b, c));
		long r = 2 * 10e9;
		while (l < r) {
			long m = l + (r - l) / 2;
			long count = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
			if (count < n) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		return l;
	}
};

