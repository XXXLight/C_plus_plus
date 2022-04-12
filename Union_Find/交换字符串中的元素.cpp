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
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		string res(s); //拷贝构造
		int n = s.size(); //并查集元素个数
		UF* uf = new UF(n); //构造函数
		for (auto e : pairs) {
			uf->union_(e[0], e[1]);
		}

		// 想到用什么数据结构很重要
		// 键：树根节点(int) 值：在该树根上的节点(vector<int>)
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[uf->find(i)].push_back(i);
		}

		// auto&[u, v] : mp学习
		for (auto&[u, v] : mp) {
			// 取出来排序
			vector<int> index = v;
			string tmp;
			for (auto e : v) {
				tmp += s[e];
			}
			sort(tmp.begin(), tmp.end());
			// 排好序放回去，利用计数器
			int cnt = 0;
			for (auto e : index) {
				res[e] = tmp[cnt++];
			}
		}

		return res;
	}
};