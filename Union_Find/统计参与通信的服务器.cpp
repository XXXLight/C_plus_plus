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
	int countServers(vector<vector<int>>& grid) {
		int row = grid.size(); //行数
		int col = grid[0].size(); //列数
		int len = row * col; // 并查集元素个数
		UF *uf = new UF(len); //调用接口，构造函数

		//映射
		vector<int> v; //将坐标拉成一维，即“降维”
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 1) {
					v.push_back(i*col + j); // i * 列 + j
				}
			}
		}

		//并查集合并操作
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i] % col == v[j] % col || v[i] / col == v[j] / col) //检查是否“同行”/ “同列”
				{
					uf->union_(v[i], v[j]); //合并操作
				}
			}
		}
		//对parent数组处理一下
		unordered_map<int, vector<int>> mp; //键：树根节点 值：在该树根中的节点
		int* parent_res = new int[len];
		parent_res = uf->parent;
		for (int i = 0; i < len; i++)
			mp[uf->find(i)].push_back(i);
		int res = 0;
		for (auto&[u, v] : mp) {
			if (v.size() > 1)
				res += v.size();
		}
		return res;
	}
};