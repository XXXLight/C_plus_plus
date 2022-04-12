#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int a = 0, b = 0, c = 0;
		vector<int> dp(n, 1);
		for (int i = 1; i < n; i++) {
			int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
			dp[i] = min(min(n2, n3), n5);
			if (dp[i] == n2) a++;	// 注意这里写成if else 不行，写成分支只执行了一条语句，此处三条语句都执行了
			if (dp[i] == n3) b++;
			if (dp[i] == n5) c++;
		}
		return dp[n - 1];
	}
};