#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int H) {
		int lo = 1, hi = pow(10, 9);
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			if (possible(piles, H, mi))
				hi = mi;
			else
				lo = mi + 1;
		}
		return lo;
	}

	// Can Koko eat all bananas in H hours with eating speed K?
	bool possible(vector<int>& piles, int H, int K) {
		int time = 0;
		for (int p : piles)
			time += ceil(1.0*p / K);// 直接对p/k取整是没有用的，需要对算出来的小数进行取整
		return time <= H;
	}
};

