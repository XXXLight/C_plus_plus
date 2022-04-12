#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int pileBox(vector<vector<int>>& box) {
		int len = box.size();
		sort(box.begin(), box.end()); //Ĭ�ϵ������ǰ��յ�һ��ά��
		vector<int> dp(len);
		int res = 0;
		for (int i = 0; i < len; i++) {
			dp[i] = box[i][2];
			// j<=i �� j<i ���ɣ����鲻Ҫ�еȺ�
			for (int j = 0; j <= i; j++) {
				// ������������ȱһ����
				if (box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2]) {
					dp[i] = max(dp[i], dp[j] + box[i][2]);
				}
			}
			res = max(dp[i], res);
		}
		return res;
	}
};