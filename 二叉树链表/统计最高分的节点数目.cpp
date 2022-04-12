#include<bits/stdc++.h>
using namespace std;

class Solution {
	int n, maxCnt;
	long maxVal;
	vector<vector<int>> adj;
	vector<int> cnt;

	void dfs(int v) {
		cnt[v] = 1;
		/* dfs求节点的个数, 包含子节点 */
		for (auto u : adj[v]) {
			dfs(u);
			cnt[v] += cnt[u];
		}

		/* 求删除该节点后, 该节点的分数 */
		long curVal = max(1, n - cnt[v]); /* 除去根节点的节点数目 */
		for (auto u : adj[v]) { /* 子节点的节点数 */
			curVal *= cnt[u];
		}
		if (curVal > maxVal) { /* 更新最大值和个数 */
			maxVal = curVal;
			maxCnt = 1;
		}
		else if (curVal == maxVal) {
			maxCnt++;
		}
	}

public:
	int countHighestScoreNodes(vector<int>& parents) {
		n = parents.size();
		adj = vector<vector<int>>(n);
		cnt = vector<int>(n);
		maxVal = 0;
		maxCnt = 0;
		for (int i = 1; i < n; i++) { /* 建树 */
			int parent = parents[i];
			adj[parent].push_back(i);
		}
		dfs(0); /* dfs求节点的个数 */
		return maxCnt;
	}
};

