#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int pileBox(vector<vector<int>>& box) {
		int len = box.size();
		sort(box.begin(), box.end()); //默认的排序是按照第一个维度
		vector<int> dp(len);
		int res = 0;
		for (int i = 0; i < len; i++) {
			dp[i] = box[i][2];
			// j<=i 或 j<i 都可，建议不要有等号
			for (int j = 0; j <= i; j++) {
				// 以下三个条件缺一不可
				if (box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2]) {
					dp[i] = max(dp[i], dp[j] + box[i][2]);
				}
			}
			res = max(dp[i], res);
		}
		return res;
	}
};