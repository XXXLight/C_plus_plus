#include<bits/stdc++.h>
using namespace std;


//  9223372036854775807 2147483647 2147483647
//  cout << LLONG_MAX << " " << LONG_MAX << " " << INT_MAX;


typedef long long LL;
class Solution {
public:
	long long gridGame(vector<vector<int>>& grid) {
		int len = grid[0].size();
		vector<LL> preSum1(len + 1, 0), preSum2(len + 1, 0);
		for (int i = 0; i < len; i++) {
			preSum1[i + 1] = preSum1[i] + grid[0][i];
			preSum2[i + 1] = preSum2[i] + grid[1][i];
		}
		LL S1 = LLONG_MAX;//注意long long的最大值
		for (int k = 0; k < len; k++) {
			LL sum2 = max(preSum1[len] - preSum1[k + 1], preSum2[k]);
			S1 = min(sum2, S1);
		}
		return S1;
	}
};