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
		if (size[rootA] < size[rootB]) swap(rootA, rootB);// B是大树，则交换，使得B是小树，A是大树
		size[rootA] += size[rootB];
		parent[rootB] = rootA;// B（小树）合并到A（大树）上
		setCount--;
	}

	int findSet(int x)
	{
		return x == parent[x] ? x : (parent[x] = findSet(parent[x]));
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

// 最小生成树算法其实非常简单
class Solution {
public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		UF uf(n + 1);
		int lenW = wells.size(), lenP = pipes.size();
		for (int i = 0; i < lenW; i++) {
			pipes.push_back({ 0,i + 1,wells[i] });
		}
		sort(pipes.begin(), pipes.end(), [](auto& e1, auto& e2) {// 加不加引用区别非常大
			return e1[2] < e2[2];
		});
		int res = 0;
		for (auto& e : pipes) {
			if (!uf.checkAB(e[0], e[1])) {
				uf.unionAB(e[0], e[1]);
				res += e[2];
			}
		}
		return res;
	}
};