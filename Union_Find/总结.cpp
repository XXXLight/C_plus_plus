#include<bits/stdc++.h>
using namespace std;

// 并查集真的很简单，并查集是树形结构
// 路径压缩：https://www.runoob.com/data-structures/union-find-compress.html
// 写法1：完全没有路径压缩
	/*int findSet(int x) {
		while (x != parent[x]) {
			x = parent[x];
		}
		return x;
	}*/
	// 路径压缩方法1：
	//int findSet(int x) {
	//	while (parent[x] != x) {
	//		// 进行路径压缩
	//		parent[x] = parent[parent[x]]; //将x用parent[x]换元
	//		x = parent[x];
	//	}
	//	return x;
	//}
	// 路径压缩方法2：
	/*int findSet(int x)
	{
		return x == parent[x] ? x : (parent[x] = findSet(parent[x]));
	}*/
class UF {
public:
	vector<int> parent;
	int setCount;// 连通分量的个数
	UF(int n) {
		parent.resize(n);
		setCount = n;
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	void unionAB(int a, int b) {
		int fa = findSet(a);
		int fb = findSet(b);
		if (fa != fb) {
			setCount--;// 合并了，连通分量的数量减少
			parent[fa] = fb;
		}
	}
	
	int findSet(int x)
	{
		if (parent[x] != x) {
			parent[x] = findSet(parent[x]);
		}
		// 因为parent[x]==x,所以return parent[x]或x都可以
		return parent[x];
	}
	
	bool checkAB(int a, int b) {
		int fa = findSet(a);
		int fb = findSet(b);
		if (fa == fb) return true;
		return false;
	}
};


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