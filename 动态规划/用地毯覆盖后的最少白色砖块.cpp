#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
		int len = floor.size();
		vector<vector<int>> dp(numCarpets + 1, vector<int>(len, 0));
		vector<int> count(len); //��j��ذ��Ƿ�Ϊ��ɫ
		dp[0][0] = floor[0] == '1' ? 1 : 0;
		for (int i = 1; i < len; ++i) {
			dp[0][i] = dp[0][i - 1];
			if (floor[i] == '1') dp[0][i]++, count[i] = 1;
		}
		for (int i = 1; i <= numCarpets; ++i) {
			for (int j = 0; j < len; ++j) {
				if (j < carpetLen) dp[i][j] = 0; //����carpetLen��ש�����˵�̺���ն���ʣ��0���ɫש��
				else dp[i][j] = min(dp[i][j - 1] + count[j], dp[i - 1][j - carpetLen]);
			}
		}
		return dp[numCarpets][len - 1];
	}
};

