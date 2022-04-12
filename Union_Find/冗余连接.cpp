#include<bits/stdc++.h>	
using namespace std;

class UF {
public:
	// 记录连通分量个数
	int count;
	// 存储若干棵树
	int* parent;
	// 记录树的“重量”
	int* size;

	UF(int n) {
		this->count = n;
		parent = new int[n];
		size = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	/* 将 p 和 q 连通 */
	void union_(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;

		// 小树接到大树下面，较平衡
		if (size[rootP] > size[rootQ]) {
			parent[rootQ] = rootP;
			size[rootP] += size[rootQ];
		}
		else {
			parent[rootP] = rootQ;
			size[rootQ] += size[rootP];
		}
		count--;
	}

	/* 判断 p 和 q 是否互相连通 */
	bool connected(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		// 处于同一棵树上的节点，相互连通
		return rootP == rootQ;
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

	int count_num() {
		return this->count;
	}
};


class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> res;
		UF *uf = new UF(1001); //构造函数，构造并查集
		for (int i = 0; i < edges.size(); i++) {
			if (!uf->connected(edges[i][0], edges[i][1]))
				uf->union_(edges[i][0], edges[i][1]);
			else res = { edges[i][0], edges[i][1] };//连通了就是答案了
		}
		return res;
	}
};