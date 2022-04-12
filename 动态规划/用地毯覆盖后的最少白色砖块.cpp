#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
		int len = floor.size();
		vector<vector<int>> dp(numCarpets + 1, vector<int>(len, 0));
		vector<int> count(len); //第j块地板是否为白色
		dp[0][0] = floor[0] == '1' ? 1 : 0;
		for (int i = 1; i < len; ++i) {
			dp[0][i] = dp[0][i - 1];
			if (floor[i] == '1') dp[0][i]++, count[i] = 1;
		}
		for (int i = 1; i <= numCarpets; ++i) {
			for (int j = 0; j < len; ++j) {
				if (j < carpetLen) dp[i][j] = 0; //少于carpetLen块砖块用了地毯最终都会剩余0块白色砖块
				else dp[i][j] = min(dp[i][j - 1] + count[j], dp[i - 1][j - carpetLen]);
			}
		}
		return dp[numCarpets][len - 1];
	}
};

