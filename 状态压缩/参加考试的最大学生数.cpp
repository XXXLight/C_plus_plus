#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxStudents(vector<vector<char>>& seats) {
		int m = seats.size();
		if (m == 0) return 0;
		int n = seats[0].size();
		int ans = 0;
		vector<vector<int>>dp(m, vector<int>(1 << n, 0));//每一行有(1<<n)-1种情况
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 1 << n; j++) {
				if (!check(j, seats, i) || !ok(j)) continue;//判断是否合法
				int num = __builtin_popcount(j);//这一行考生数量
				if (i == 0) dp[i][j] = num;//第一行只需要管自己这行即可
				else {
					for (int k = 0; k < 1 << n; k++) {//判断j|k是否合法
						if (ok(j | k)) dp[i][j] = max(dp[i][j], dp[i - 1][k] + num);
					}
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
	bool check(int k, vector<vector<char>>& seats, int pos) {//判断该状态是否与实际情况符合，即有1的位置的座位是否坏了，坏了该状态就不行
		int i = 0;
		while (k) {
			int a = k % 2;
			if (a == 1 && seats[pos][i] == '#') return false;
			k /= 2;
			i++;
		}
		return true;
	}
	bool ok(int p) {//判断该状态是否有2个1相邻，有两个1相邻表示这个人的旁边或者左前或者右前有人，那么该状态不行
		int pre = 0;
		while (p) {
			int a = p % 2;
			if (a == 1 && pre == 1) return false;
			if (a == 1) pre = 1;
			else pre = 0;
			p /= 2;
		}
		return true;
	}
};