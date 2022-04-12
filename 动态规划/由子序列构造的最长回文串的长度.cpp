#include<bits/stdc++.h>
using namespace std;

// 由516题改编
const int maxn = 2000 + 5;
int dp[maxn][maxn];
class Solution {
public:
	int longestPalindrome(string word1, string word2) {
		string word = word1 + word2;
		int n1 = word1.size(), n2 = word2.size();
		memset(dp, 0, sizeof dp); //学会memset初始化方法
		int ans = 0;
		for (int i = 0; i < word.size(); i++) dp[i][i] = 1;
		for (int i = word.size() - 1; i >= 0; i--) {
			for (int j = i + 1; j < word.size(); j++) {
				if (word[i] == word[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
					if (i < n1 && j >= n1) ans = max(ans, dp[i][j]); // 确保字符串非空
				}
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		return ans;
	}
};