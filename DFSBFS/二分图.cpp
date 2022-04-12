#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
	// BFS
	bool setColor(vector<vector<int>>& graph, vector<int>& colors, int i, int color) {
		colors[i] = color;
		queue<int> que;
		que.push(i);

		while (!que.empty()) {
			int v = que.front();
			que.pop();

			for (auto& neb : graph[v]) {
				// 已着色，但是不符合一条边两个节点不同颜色的要求
				if (colors[neb] >= 0) {
					if (colors[neb] == colors[v]) {
						return false;
					}
				}
				// 未着色，按照要求着色
				else {
					que.push(neb);
					colors[neb] = 1 - colors[v];
				}
			}
		}
		return true;
	}

public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<int> colors(graph.size(), -1);

		for (int i = 0; i < graph.size(); ++i) {
			if (colors[i] == -1) {
				if (!setColor(graph, colors, i, 0)) {
					return false;
				}
			}
		}
		return true;
	}
};

