#include<bits/stdc++.h>
using namespace std;


class UF {
public:
	// 记录连通分量个数
	int setCount;
	// 存储若干棵树
	vector<int> parent;
	// 记录树的“重量”
	vector<int> size;

	UF(int n) {
		this->setCount = n;
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	/* 将 a 和 b 连通 */
	void unionAB(int a, int b) {
		int rootA = findSet(a);
		int rootB = findSet(b);
		if (rootA == rootB)
			return;
		// 小树接到大树下面，较平衡
		if (size[rootA] < size[rootB]) swap(rootA, rootB);
		size[rootA] += size[rootB];
		parent[rootB] = rootA;
		setCount--;
	}

	/* 返回节点 x 的根节点 */
	int findSet(int x) {
		while (parent[x] != x) {
			// 进行路径压缩
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	/* 判断 a 和 b 是否互相连通 */
	bool checkAB(int a, int b) {
		int rootA = findSet(a);
		int rootB = findSet(b);
		// 处于同一棵树上的节点，相互连通
		return rootA == rootB;
	}

	int count_num() {
		return this->setCount;
	}
};


class Solution {
public:
	int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // 四个方向向量
	int largestIsland(vector<vector<int>>& grid) {
		int n = grid.size();
		UF uf(n*n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {// 当前位置是1，向四个方向合并
					for (int k = 0; k < 4; k++) {// 注意变量用k，防止重复
						int newX = i + dirX[k], newY = j + dirY[k];// 新的坐标
						// 坐标不越界
						if (newX >= 0 && newX < n&&newY >= 0 && newY < n&&grid[newX][newY] == 1) {
							uf.unionAB(i*n + j, newX*n + newY);
						}
					}
				}
			}
		}
		unordered_map<int, vector<int>> mp;// 根节点----》根节点包含集合
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					mp[uf.findSet(i*n + j)].push_back(i*n + j);
				}
			}
		}
		// 没有0的话，直接返回矩阵面积
		int cnt = 0;
		for (auto&[u, v] : mp) {
			cnt += v.size();
		}
		if (cnt == n * n) return n * n;

		set<int> flag;
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					int sum = 1;
					flag.clear();// 注意这里不能少
					for (int k = 0; k < 4; k++) {
						int newX = i + dirX[k], newY = j + dirY[k];
						if (newX >= 0 && newX < n&&newY >= 0 && newY < n&&grid[newX][newY] == 1 && !flag.count(uf.findSet(newX*n + newY))) {
							flag.insert(uf.findSet(newX*n + newY));
							sum += mp[uf.findSet(newX*n + newY)].size();
						}
					}
					res = max(res, sum);
				}
			}
		}
		return res;
	}
};



