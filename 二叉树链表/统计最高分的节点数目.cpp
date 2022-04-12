#include<bits/stdc++.h>
using namespace std;

class Solution {
	int n, maxCnt;
	long maxVal;
	vector<vector<int>> adj;
	vector<int> cnt;

	void dfs(int v) {
		cnt[v] = 1;
		/* dfs��ڵ�ĸ���, �����ӽڵ� */
		for (auto u : adj[v]) {
			dfs(u);
			cnt[v] += cnt[u];
		}

		/* ��ɾ���ýڵ��, �ýڵ�ķ��� */
		long curVal = max(1, n - cnt[v]); /* ��ȥ���ڵ�Ľڵ���Ŀ */
		for (auto u : adj[v]) { /* �ӽڵ�Ľڵ��� */
			curVal *= cnt[u];
		}
		if (curVal > maxVal) { /* �������ֵ�͸��� */
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
		for (int i = 1; i < n; i++) { /* ���� */
			int parent = parents[i];
			adj[parent].push_back(i);
		}
		dfs(0); /* dfs��ڵ�ĸ��� */
		return maxCnt;
	}
};

