#include<bits/stdc++.h>
using namespace std;


// 并查集模板
class UF {
public:
	vector<int> parent;
	int setCount;
	UF(int n) {
		parent.resize(n);
		setCount = n;
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	int find(int x) {
		while (parent[x] != x) {
			// 进行路径压缩
			parent[x] = parent[parent[x]]; //将x用parent[x]换元
			x = parent[x];
		}
		return x;
	}
	bool check(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		if (fa == fb) return true;
		return false;
	}
	void unionAB(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		setCount--;
		if (fa != fb) parent[fa] = fb;
	}
};

class Solution {
public:
	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		UF Alice(n), Bob(n);
		int ans = 0;

		// 节点编号改为从 0 开始
		for (auto& edge : edges) {
			--edge[1];
			--edge[2];
		}

		// 公共边
		for (const auto& edge : edges) {
			if (edge[0] == 3) {
				if (Bob.check(edge[1], edge[2])) {
					++ans;
				}
				else {
					Alice.unionAB(edge[1], edge[2]);
					Bob.unionAB(edge[1], edge[2]);
				}
			}
		}

		// 独占边
		for (const auto& edge : edges) {
			if (edge[0] == 1) {
				// Alice 独占边
				if (Alice.check(edge[1], edge[2])) {
					++ans;
				}
				else {
					Alice.unionAB(edge[1], edge[2]);
				}
			}
			else if (edge[0] == 2) {
				// Bob 独占边
				if (Bob.check(edge[1], edge[2])) {
					++ans;
				}
				else {
					Bob.unionAB(edge[1], edge[2]);
				}
			}
		}

		if (Alice.setCount != 1 || Bob.setCount != 1) {
			return -1;
		}
		return ans;
	}
};

