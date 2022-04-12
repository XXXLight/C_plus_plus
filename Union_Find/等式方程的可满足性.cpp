#include<bits/stdc++.h>
using namespace std;

class UF {
public:
	// ��¼��ͨ��������
	int count;
	// �洢���ɿ���
	int* parent;
	// ��¼���ġ�������
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

	/* �� p �� q ��ͨ */
	void union_(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;

		// С���ӵ��������棬��ƽ��
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

	/* �ж� p �� q �Ƿ�����ͨ */
	bool connected(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		// ����ͬһ�����ϵĽڵ㣬�໥��ͨ
		return rootP == rootQ;
	}

	/* ���ؽڵ� x �ĸ��ڵ� */
	int find(int x) {
		while (parent[x] != x) {
			// ����·��ѹ��
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
	bool equationsPossible(vector<string>& equations) {
		UF *uf = new UF(26);	//���첢�鼯����
		for (auto e : equations) {
			int l = e[0] - 'a'; //��һ���ַ�
			int r = e[3] - 'a'; //���һ���ַ�
			if (e[1] == '=')
				uf->union_(l, r); //�ǵȺ���ϲ�
		}
		for (auto e : equations) {
			int l = e[0] - 'a';
			int r = e[3] - 'a';
			if (e[1] == '!') {
				if (uf->connected(l, r))
					return false;
			}
		}
		return true;
	}
};




class UF {
public:
	vector<int> parent;
	UF(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	/* �� p �� q ��ͨ */
	void union_(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP != rootQ) parent[rootP] = rootQ;
	}
	/* �ж� p �� q �Ƿ�����ͨ */
	bool connected(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		return rootP == rootQ;
	}
	/* ���ؽڵ� x �ĸ��ڵ� */
	int find(int x) {
		while (parent[x] != x) {
			x = parent[x];
		}
		return x;
	}
};

class Solution {
public:
	bool equationsPossible(vector<string>& equations) {
		UF *uf = new UF(26);
		for (auto e : equations) {
			int l = e[0] - 'a';
			int r = e[3] - 'a';
			if (e[1] == '=')
				uf->union_(l, r);
		}
		for (auto e : equations) {
			int l = e[0] - 'a';
			int r = e[3] - 'a';
			if (e[1] == '!') {
				if (uf->connected(l, r))
					return false;
			}
		}
		return true;
	}
};