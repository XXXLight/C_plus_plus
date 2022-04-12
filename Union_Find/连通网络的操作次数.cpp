#include<bits/stdc++.h>
using namespace std;

class UF {
public:
	vector<int> parent;
	UF(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	// ·��ѹ��
	int find(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	void unionAB(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		if (fa != fb) parent[fa] = parent[fb];
	}
	int check(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		return fa == fb;
	}
};
class Solution {
public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		UF* uf = new UF(n);
		for (auto e : connections) {
			uf->unionAB(e[0], e[1]);
		}
		unordered_map<int, vector<int>> mp;
		// ���ɣ� parent[i] ====>  vector i��ӳ�� mp.size()���Ƕѵ�����
		for (int i = 0; i < n; i++) {
			mp[uf->find(i)].push_back(i);
		}
		if (connections.size() < n - 1) {
			return -1;
		}
		return mp.size() - 1;
	}
};
