#include<bits/stdc++.h>
using namespace std;


// 超时就要考虑换另一个模板
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

class Solution {
public:
	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		int n1 = edgeList.size(), n2 = queries.size();
		// 对边权进行排序
		sort(edgeList.begin(), edgeList.end(), [](auto& e1, auto& e2) {
			return e1[2] < e2[2];
		});
		// queries最后一维增加一个索引
		for (int i = 0; i < n2; i++) {
			queries[i].push_back(i);
		}
		// 查询也同样按照边权进行排序
		sort(queries.begin(), queries.end(), [](auto& e1, auto& e2) {
			return e1[2] < e2[2];
		});
		UF uf(n);
		// 结果集
		vector<bool> res(n2, 0);
		int k = 0;// 注意k=0写在外面
		for (int i = 0; i < n2; i++) {
			// 遍历每个查询点，此时由于排序以及打乱了索引
			int p1 = queries[i][0], p2 = queries[i][1], p3 = queries[i][2], p4 = queries[i][3];
			while (k < n1&&edgeList[k][2] < p3) {
				uf.unionAB(edgeList[k][0], edgeList[k][1]);
				k++;
			}
			int r = uf.checkAB(p1, p2);
			res[p4] = r;
		}
		return res;
	}
};