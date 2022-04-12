#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<int, vector<int>> mp;
	bool DFS(int st, int en) {
		if (st == en) return true;
		for (auto e : mp[st]) {
			if (DFS(e, en))
				return true;
		}
		return false;
	}
	bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
		for (auto e : graph) {
			mp[e[0]].push_back(e[1]);
		}
		if (DFS(start, target)) return true;
		return false;
	}
};