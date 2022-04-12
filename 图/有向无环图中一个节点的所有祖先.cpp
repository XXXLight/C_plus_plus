#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& vertex) {
		vector<vector<int>> edges(n);
		int indegree[n]; memset(indegree, 0, sizeof(indegree));
		for (auto &edge : vertex) {
			int u = edge[0], v = edge[1];
			edges[u].push_back(v);//vµÄ¸¸Ç×ÊÇu
			++indegree[v];
		}
		unordered_map<int, unordered_set<int>> parents;
		vector<vector<int>> res(n);
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (indegree[i] == 0)q.push(i);
		}
		while (!q.empty()) {
			int current = q.front(); q.pop();
			for (int i = 0; i < edges[current].size(); ++i) {
				int child = edges[current][i];
				if (--indegree[child] == 0) {
					q.push(edges[current][i]);
				}
				parents[child].insert(current);
				for (auto &item : parents[current]) {
					parents[child].insert(item);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (auto &item : parents[i]) {
				res[i].push_back(item);
			}
			sort(res[i].begin(), res[i].end());
		}
		return res;
	}
};

