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
	// 去除连接操作
	void disConnect(int x) {
		parent[x] = x;
	}

	int count_num() {
		return this->setCount;
	}
};

class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		UF uf(n);
		uf.unionAB(0, firstPerson);
		sort(meetings.begin(), meetings.end(), [](auto &e1, auto &e2) {
			return e1[2] < e2[2];
		});
		int m = meetings.size();
		for (int i = 0; i < m; ++i) {
			//同一时间的建立连接
			int j = i + 1;
			while (j < m && meetings[j][2] == meetings[i][2])++j;
			//开始合并
			for (int k = i; k < j; ++k) {
				uf.unionAB(meetings[k][0], meetings[k][1]);
			}
			//然后判断是不是跟已知的专家一块的，
			for (int k = i; k < j; ++k) {
				if (!uf.checkAB(meetings[k][0], 0)) {
					uf.disConnect(meetings[k][0]);
					uf.disConnect(meetings[k][1]);
				}
			}
			i = j - 1;
		}
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[uf.findSet(i)].push_back(i);
		}
		int r = uf.findSet(0);
		return mp[r];
	}
};