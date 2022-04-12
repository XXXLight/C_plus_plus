#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<long long> v;
		for (long long a = 1; a <= INT_MAX; a = a * 2)
			for (long long b = 1; a*b < INT_MAX; b = b * 3)
				for (long long c = 1; a*b*c < INT_MAX; c = c * 5)
				{
					v.push_back(a*b*c);
				}
		sort(v.begin(), v.end());
		return v[n - 1];
	}
};