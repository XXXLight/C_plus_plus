#include<bits/stdc++.h>
using namespace std;
// https://leetcode-cn.com/problems/process-restricted-friend-requests/solution/bing-cha-ji-ge-ren-gan-jue-hen-hao-li-ji-bvxp/

// 并查集模板
class UnionFind {
public:
	vector<int> parent;
	vector<int> size;
	int n;

public:
	UnionFind(int _n) : n(_n), parent(_n), size(_n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}
	// 路径压缩版findSet
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
		// 遍历请求集合
		for (int i = 0; i < requests.size(); ++i) {
			int x = requests[i][0], y = requests[i][1];
			bool f = true;// 是否可以将x y进行合并
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
			if (f) {// 可以将x和y进行合并
				uf.unite(x, y);
				res.push_back(1);
			}
			else {// 不可以将x和y进行合并
				res.push_back(0);
			}
		}
		return res;
	}
};






// 超时就要考虑换另一个模板
class UF {
public:
	// 记录连通分量个数
	int count;
	// 存储若干棵树
	vector<int> parent;
	// 记录树的“重量”
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

	/* 将 p 和 q 连通 */
	void unionAB(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;

		// 小树接到大树下面，较平衡
		if (size[rootP] < size[rootQ]) swap(rootP, rootQ);
		size[rootP] += size[rootQ];
		parent[rootQ] = rootP;
		count--;
	}

	/* 返回节点 x 的根节点 */
	int find(int x) {
		while (parent[x] != x) {
			// 进行路径压缩
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	/* 判断 p 和 q 是否互相连通 */
	bool check(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		// 处于同一棵树上的节点，相互连通
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
		for (auto& re : requests) {// 去掉&的遍历方式会超时,因为会拷贝数据
			int f0 = re[0], f1 = re[1];
			bool flag = true;
			if (not uf.check(f0, f1)) {
				for (auto& st : restrictions) {// 去掉&的遍历方式会超时
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