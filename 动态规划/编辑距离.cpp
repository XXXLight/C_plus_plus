#include<bits/stdc++.h>
using namespace std;

// 注意先画表格，一目了然
// 已知元素，递推关系决定了遍历方式
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		// dp数组的索引和字符串的索引存在偏差
		for (int i = 0; i <= len1; i++) dp[i][0] = i;
		for (int i = 0; i <= len2; i++) dp[0][i] = i;
		// 枚举方式 增增
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				// 注意这里的下标是dp数组的
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				}
			}
		}
		return dp[len1][len2];
	}
};