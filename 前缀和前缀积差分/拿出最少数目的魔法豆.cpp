#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long minimumRemoval(vector<int>& beans) {
		int n = beans.size();
		sort(beans.begin(), beans.end());
		long long prefixSum[n];
		prefixSum[0] = beans[0];
		for (int i = 1; i < n; ++i)prefixSum[i] = prefixSum[i - 1] + beans[i];
		long long res = (prefixSum[n - 1] - prefixSum[0]) - (long long)beans[0] * (n - 1);
		for (int i = 1; i < n; ++i) {
			//以当前位置为最终结果的话，左边所有的位置都得减为0
			res = min(prefixSum[i - 1] + (prefixSum[n - 1] - prefixSum[i]) - (long long)(n - i - 1) * beans[i], res);
		}
		return res;
	}
};

