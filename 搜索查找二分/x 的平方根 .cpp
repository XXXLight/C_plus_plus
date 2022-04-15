#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int mySqrt(int x) {
		int l = 0, r = x;
		while (l <= r) {
			int m = (l + r) / 2;
			if (1LL * m*m == x) return m;
			else if (1LL * m*m < x) l = m + 1;
			else if (1LL * m*m > x) r = m - 1;
		}
		if (1LL * l*l > x) return l - 1;
		return l;
	}
};


class Solution {
public:
	int mySqrt(int x) {
		int l = 0, r = x;
		while (l <= r) {
			int m = (l + r) / 2;
			if (1LL * m*m == x) return m;
			else if (1LL * m*m < x) l = m + 1;// 一定要是m+1
			else if (1LL * m*m > x) r = m - 1;
		}
		// 退出循环时l>r，所以r是下界，l是上界
		return r;
	}
};