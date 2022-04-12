#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 邻接矩阵用vector<vector<int>>
// 邻接表用unordered_map<int, vector<int>> ?，出现负数，只能使用哈希表

class Solution {
public:
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, vector<int>> adj;//邻接表，打印出来就知道长什么样子了
		unordered_map<int, int> in_deg; //每个节点的入度
		// 有向图，双向连接
		for (auto &v : adjacentPairs) { // v是adjacentPairs的元素，是一个vector<int>
			adj[v[0]].emplace_back(v[1]);
			adj[v[1]].emplace_back(v[0]);
			in_deg[v[0]]++;
			in_deg[v[1]]++;
		}
		int start;
		for (auto [num, deg] : in_deg) { //属性===>C++====>语言=====>C++17才行，否则会报错，换一种方式遍历map
			if (deg == 1) { //入度为1是开始节点
				start = num;
				break;
			}
		}
		//以下是BFS，用了开始节点start和邻接表
		queue<int> q;
		q.emplace(start);
		vector<int> ans;
		unordered_set<int> vis;
		vis.emplace(start);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			ans.emplace_back(u);
			for (int v : adj[u]) {
				if (!vis.count(v)) { //没有访问过
					vis.emplace(v); //标记为已经访问过
					q.emplace(v);
				}
			}
		}
		return ans;
	}
};