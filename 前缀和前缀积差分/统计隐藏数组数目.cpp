#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int numberOfArrays(vector<int>& differences, int lower, int upper) {
		vector<long long> preSum;
		preSum.push_back(0);
		long long a = 0;
		for (auto e : differences) {
			a += e;
			preSum.push_back(a);
		}
		int vMax = *max_element(preSum.begin(), preSum.end());
		int vMin = *min_element(preSum.begin(), preSum.end());
		int res = 0;
		for (int i = lower; i <= upper; i++) {
			if (vMin + i >= lower && vMin + i <= upper && vMax + i >= lower && vMax + i <= upper) res++;
		}
		return res;
	}
};