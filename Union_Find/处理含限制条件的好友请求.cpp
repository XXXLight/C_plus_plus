#include<bits/stdc++.h>
using namespace std;
// https://leetcode-cn.com/problems/process-restricted-friend-requests/solution/bing-cha-ji-ge-ren-gan-jue-hen-hao-li-ji-bvxp/

// ���鼯ģ��
class UnionFind {
public:
	vector<int> parent;
	vector<int> size;
	int n;

public:
	UnionFind(int _n) : n(_n), parent(_n), size(_n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}
	// ·��ѹ����findSet
	int findset(int x) {
		return parent[x] == x ? x : parent[x] = findset(parent[x]);
	}

	bool unite(int x, int y) {
		x = findset(x);
		y = findset(y);
		if (x == y) {
			return false;
		}
		if (size[x] < size[y]) {
			swap(x, y);
		}
		parent[y] = x;
		size[x] += size[y];
		return true;
	}

	bool connected(int x, int y) {
		x = findset(x);
		y = findset(y);
		return x == y;
	}
};
class Solution {
public:
	vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
		vector<bool> res;
		UnionFind uf(n);
		// �������󼯺�
		for (int i = 0; i < requests.size(); ++i) {
			int x = requests[i][0], y = requests[i][1];
			bool f = true;// �Ƿ���Խ�x y���кϲ�
			if (!uf.connected(x, y)) {
				for (int j = 0; j < restrictions.size(); ++j) {
					int p = restrictions[j][0], q = restrictions[j][1];
					if ((uf.connected(p, x) && uf.connected(q, y))
						|| (uf.connected(p, y) && uf.connected(q, x))) {
						f = false;
						break;
					}
				}
			}
			if (f) {// ���Խ�x��y���кϲ�
				uf.unite(x, y);
				res.push_back(1);
			}
			else {// �����Խ�x��y���кϲ�
				res.push_back(0);
			}
		}
		return res;
	}
};






// ��ʱ��Ҫ���ǻ���һ��ģ��
class UF {
public:
	// ��¼��ͨ��������
	int count;
	// �洢���ɿ���
	vector<int> parent;
	// ��¼���ġ�������
	vector<int> size;

	UF(int n) {
		this->count = n;
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	/* �� p �� q ��ͨ */
	void unionAB(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;

		// С���ӵ��������棬��ƽ��
		if (size[rootP] < size[rootQ]) swap(rootP, rootQ);
		size[rootP] += size[rootQ];
		parent[rootQ] = rootP;
		count--;
	}

	/* ���ؽڵ� x �ĸ��ڵ� */
	int find(int x) {
		while (parent[x] != x) {
			// ����·��ѹ��
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	/* �ж� p �� q �Ƿ�����ͨ */
	bool check(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		// ����ͬһ�����ϵĽڵ㣬�໥��ͨ
		return rootP == rootQ;
	}

	int count_num() {
		return this->count;
	}
};
class Solution {
public:
	vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
		vector<bool> res;
		UF uf(n);
		for (auto& re : requests) {// ȥ��&�ı�����ʽ�ᳬʱ,��Ϊ�´������
			int f0 = re[0], f1 = re[1];
			bool flag = true;
			if (not uf.check(f0, f1)) {
				for (auto& st : restrictions) {// ȥ��&�ı�����ʽ�ᳬʱ
					int s0 = st[0], s1 = st[1];
					if ((uf.check(f0, s0) && uf.check(f1, s1)) || (uf.check(f0, s1) && uf.check(f1, s0))) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				uf.unionAB(f0, f1);
				res.push_back(1);
			}
			else {
				res.push_back(0);
			}
		}
		return res;
	}
};