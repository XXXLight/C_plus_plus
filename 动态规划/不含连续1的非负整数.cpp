#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	// Integer dp[];
	int findIntegers(int n) {
		// dp=new Integer[n+1];
		return 1 + dfs(1, n);
	}
	int dfs(int cur, int n) {
		if (cur > n)
			return 0;
		else {
			// if(dp[cur]!=null)
			//     return dp[cur];
			if ((cur & 1) == 1)
				return 1 + dfs(cur << 1, n);
			else
				return 1 + dfs((cur << 1) + 1, n) + dfs(cur << 1, n);
		}
	}
};


class Solution {
public:
	int findIntegers(int n) {
		vector<int> dp(31);
		dp[0] = dp[1] = 1;
		for (int i = 2; i < 31; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		int pre = 0, res = 0;
		for (int i = 29; i >= 0; --i) {
			int val = 1 << i;
			if ((n & val) != 0) {
				n -= val;
				res += dp[i + 1];
				if (pre == 1) {
					break;
				}
				pre = 1;
			}
			else {
				pre = 0;
			}

			if (i == 0) {
				++res;
			}
		}
		return res;
	}
};

