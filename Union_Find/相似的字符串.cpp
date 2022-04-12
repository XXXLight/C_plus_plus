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
	bool similiarAB(string &a, string& b) {
		if (a == b) return true;
		int len = a.size();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (a[i] != b[i]) cnt++;
		}
		if (cnt == 2) return true;
		return false;
	}
	int numSimilarGroups(vector<string>& strs) {
		int len = strs.size();
		UF uf(len);
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (similiarAB(strs[i], strs[j])) {
					uf.unionAB(i, j);
				}
			}
		}
		return uf.setCount;
	}
};