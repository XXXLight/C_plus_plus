#include<bits/stdc++.h>
using namespace std;

// 下面解法过不了,思路还是好的
class Solution {
public:
	int minDays(int n) {
		if (n == 1) return 1;
		if (n == 2 || n == 3) return 2;
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 2;
		for (int i = 3; i <= n; i++) {
			if (i % 2 == 0 && i % 3 == 0) dp[i] = min(dp[i / 2], min(dp[i / 3], dp[i - 1])) + 1;
			else if (i % 2 == 0 && i % 3 != 0) dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
			else if (i % 2 != 0 && i % 3 == 0) dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
			else dp[i] = dp[i - 1] + 1;
		}
		return dp[n];
	}
};


// 可以过
class Solution {
public:
	map<int, int> mp;
	int minDays(int n) {
		if (n == 0 || n == 1) return n;
		if (mp.count(n)) return mp[n];
		return mp[n] = min(minDays(n / 2) + n % 2 + 1, minDays(n / 3) + n % 3 + 1);
	}
};