#include<bits/stdc++.h>
using namespace std;

class UF {
public:
	// ��¼��ͨ����������union�ͼ���
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
	int findCircleNum(vector<vector<int>>& isConnected) {
		int num = isConnected.size();
		UF *uf = new UF(num);
		for (int i = 0; i < num; i++) {
			for (int j = i + 1; j < num; j++) {
				if (isConnected[i][j] == 1)
					uf->union_(i, j);
			}
		}
		return uf->count;
	}
};