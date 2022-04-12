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
	int countServers(vector<vector<int>>& grid) {
		int row = grid.size(); //����
		int col = grid[0].size(); //����
		int len = row * col; // ���鼯Ԫ�ظ���
		UF *uf = new UF(len); //���ýӿڣ����캯��

		//ӳ��
		vector<int> v; //����������һά��������ά��
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 1) {
					v.push_back(i*col + j); // i * �� + j
				}
			}
		}

		//���鼯�ϲ�����
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i] % col == v[j] % col || v[i] / col == v[j] / col) //����Ƿ�ͬ�С�/ ��ͬ�С�
				{
					uf->union_(v[i], v[j]); //�ϲ�����
				}
			}
		}
		//��parent���鴦��һ��
		unordered_map<int, vector<int>> mp; //���������ڵ� ֵ���ڸ������еĽڵ�
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