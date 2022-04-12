#include<bits/stdc++.h>
using namespace std;


class StreamRank {
public:
	int nums[50002];
	StreamRank() {
		for (int i = 0; i <= 50001; i++) {
			nums[i] = 0;
		}
	}

	void track(int x) {
		++x;
		for (int i = x; i <= 50001; i += i & (-i)) {
			++nums[i];
		}
	}

	int getRankOfNumber(int x) {
		int  res = 0;
		for (int i = x + 1; i; i -= i & (-i)) {
			res += nums[i];
		}
		return res;
	}
};

