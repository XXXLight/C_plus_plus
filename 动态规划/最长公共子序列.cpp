#include<bits/stdc++.h>
using namespace std;

// 与编辑距离对比
// 初始条件和递推关系  -----》 遍历方式
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.length();
		int len2 = text2.length();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i < len1 + 1; i++) {
			for (int j = 1; j < len2 + 1; j++) {
				// 和编辑距离一样都有偏移量
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[len1][len2];
	}
};






// 查看更新过程
class Solution {
public:
	void printV(vector<vector<int>>& dp) {
		int row = dp.size();
		int col = dp[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.length();
		int len2 = text2.length();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		printV(dp);
		for (int i = 1; i < len1 + 1; i++) {
			for (int j = 1; j < len2 + 1; j++) {
				// 和编辑距离一样都有偏移量
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				printV(dp);// 查看每次更新过程
			}
		}
		return dp[len1][len2];
	}
};