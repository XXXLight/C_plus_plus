#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int n;
	bool dp[305];// dp[i] 表示 strs[i] 是否被搜索了
	bool judge(string& a, string& b) {
		int res = 0;
		for (int i = 0; i < a.size() && res < 3; i++) if (a[i] != b[i]) res++;
		return (res == 2) | (res == 0);
	}
	int numSimilarGroups(vector<string>& strs) {
		n = strs.size();
		int res = 0;
		memset(dp, false, sizeof n);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (dp[i]) continue;// 被搜索了就跳过
			dp[i] = true;
			q.push(i);
			res++;
			while (!q.empty()) {
				int t = q.front(); q.pop();
				for (int i = 0; i < n; i++) {
					if (!dp[i] && judge(strs[t], strs[i])) {
						dp[i] = true;
						q.push(i);
					}
				}
			}
		}
		return res;
	}
};

