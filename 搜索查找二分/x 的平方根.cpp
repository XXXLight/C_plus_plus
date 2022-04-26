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
			else if (1LL * m*m < x) l = m + 1;// һ��Ҫ��m+1
			else if (1LL * m*m > x) r = m - 1;
		}
		// �˳�ѭ��ʱl>r������r���½磬l���Ͻ�
		return r;
	}
};




// ţ�ٵ�����
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) {
			return 0;
		}
		double C = x, x0 = x;
		while (1) {
			double xi = 0.5 * (x0 + C / x0);
			if (fabs(x0 - xi) < 1e-7) {
				break;
			}
			x0 = xi;
		}
		return int(x0);
	}
};

