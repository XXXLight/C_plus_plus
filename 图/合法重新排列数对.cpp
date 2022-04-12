#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> res;
	void dfs(int node, unordered_map<int, vector<int>>& nes) {
		auto& v = nes[node];
		while (v.size()) {
			auto ne = v.back();
			v.pop_back();
			dfs(ne, nes);
		}
		res.push_back(node);
	}
	vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
		unordered_map<int, vector<int>> nes;
		unordered_map<int, int> incnt;
		for (auto& p : pairs) {
			nes[p[0]].emplace_back(p[1]);
			incnt[p[1]]++;
		}
		int start = -1;
		for (const auto & p : nes) {
			int node = p.first;
			if (p.second.size() == incnt[node] + 1) {
				start = node;
			}
		}
		if (start == -1) {
			start = pairs[0][0];
		}
		dfs(start, nes);
		reverse(res.begin(), res.end());
		vector<vector<int>> ret;
		for (int i = 1; i < res.size(); ++i) {
			ret.push_back({ res[i - 1], res[i] });
		}
		return ret;
	}
};

