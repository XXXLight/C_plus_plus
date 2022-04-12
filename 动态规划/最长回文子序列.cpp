#include<bits/stdc++.h>
using namespace std;


// 理解反向遍历和斜向遍历
// 不得不说别人写的是真的用心，学贵于精
// 对比最长回文子序列和最长回文子串，一个是中心扩展，一个是逆向dp


// 逆向思维，最少删除几个成回文   等价于  最长回文子序列
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp 数组全部初始化为 0
		vector<vector<int>> dp(n, vector<int>(n, 0));
		// base case
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;
		// 反着遍历保证正确的状态转移
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				// 状态转移方程
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		// 整个 s 的最长回文子串长度
		return dp[0][n - 1];
	}
};



//             i,j-1     i,j
//		       i+1,j-1   i+1,j   由其他三个决定右上角，采用右三角自底向上遍历法
// 也可以这样写
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp 数组全部初始化为 0
		vector<vector<int>> dp(n, vector<int>(n, 0));
		// base case
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;
		// 反着遍历保证正确的状态转移
		int ans = 1;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				// 状态转移方程
				if (s[i] == s[j]) {
					// j<i的话dp[i][j]=0
					dp[i][j] = dp[i + 1][j - 1] + 2;
					ans = max(ans, dp[i][j]);
				}

				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		// 整个 s 的最长回文子串长度
		return ans;
	}
};


class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp数组可以这样开
		int dp[1001][1001] = { 0 };
		for (int i = 0; i < n; i++) dp[i][i] = 1;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};



// 调试看矩阵的更新过程
class Solution {
public:
	void printV(vector<vector<int>>& dp) {
		int len = dp.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp 数组全部初始化为 0
		vector<vector<int>> dp(n, vector<int>(n, 0));
		// base case
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;
		// 反着遍历保证正确的状态转移
		printV(dp);// 矩阵原始状态
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				// 状态转移方程
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				printV(dp);// 每更新一次，把矩阵打印出来
			}
		}
		// 整个 s 的最长回文子串长度
		return dp[0][n - 1];
	}
};